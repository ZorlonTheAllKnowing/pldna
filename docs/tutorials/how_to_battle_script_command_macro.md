## How to add new Battle Script Commands/Macros

<<<<<<< HEAD
To preface this tutorial, the battle engine upgrade has exhausted all battle script command IDs, and instead uses the `various` command to effectively add new commands. This is preferential to creating a secondary battle script command table like is done in the CFRU.

In general, `gBattlescriptCurrInstr` tracks the current battle script position as a ROM address. Fortunately, we don't need to worry about ROM addresses when using the decomps, but it is important to understand because of how the `various` command is set up.

```
.macro various battler:req, param1:req
    .byte 0x76
    .byte \battler
    .byte \param1
    .endm
```

`various` is 3 bytes in size, so if we wanted to advance to the next battle script command, we would write `gBattlescriptCurrInstr += 3`. Coincidentally, this is found at the end of `Cmd_Various` in `src/battle_script_commands.c`.

Now, how might we add a custom various command case? Here are the steps. We will use `VARIOUS_SET_SIMPLE_BEAM` as an example.
### 1. Add a definition to `include/constants/battle_script_commands.h`.

For example, `#define VARIOUS_SET_SIMPLE_BEAM   39`

### 2. Create a macro in `asm/macros/battle_script.inc`. For example:
```c
.macro setabilitysimple battler:req, ptr:req
    various \battler VARIOUS_SET_SIMPLE_BEAM
    .4byte \ptr
    .endm
```

### 3. Add your new various command ID to `Cmd_Various`. For example:
```c
    case VARIOUS_SET_SIMPLE_BEAM:
        if (IsEntrainmentTargetOrSimpleBeamBannedAbility(gBattleMons[gBattlerTarget].ability)
            || gBattleMons[gBattlerTarget].ability == ABILITY_SIMPLE)
        {
            gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 3);
        }
        else
        {
            gBattleMons[gBattlerTarget].ability = ABILITY_SIMPLE;
            RecordAbilityBattle(gActiveBattler, ABILITY_SIMPLE);
            gBattlescriptCurrInstr += 7;
        }
        return;
```

The macros' `battler` argument is the battler who will be affected/considered by your command. In our case, which battler we will try to give `ABILITY_SIMPLE`. Note that `gActiveBattler` is always set to this battler at the beginning of `Cmd_Various`.

The `ptr` argument is an extra argument that, in this case, provides a battle script to jump to in the event that we fail to set `ABILITY_SIMPLE`. We must add the `.4byte \ptr` inside our macro. So now when we want to advance to the next battle script command in our script, we must increment `gBattlescriptCurrInstr` by `7` because our overall macro is 3 bytes for the various command, and 4 bytes for the pointer. *IMPORTANT* the `return` at the end of the switch case is required because remember that `various` always defaults to `gBattlescriptCurrInstr += 3` at the very end of the function, so if we included `gBattlescriptCurrInstr += 7` with a `break`, we would end up effectively doing `gBattlescriptCurrInstr += 10`.

This behavior can be found under the `else` statement in the example above, corresponding to `ABILITY_SIMPLE` being correctly applied. If we are unable to set `ABILITY_SIMPLE`, however, notice the following `gBattlescriptCurrInstr = T1_READ_PTR(gBattlescriptCurrInstr + 3);`. This means we are jumping to the battle script provided by the pointer 3 bytes after our various command (which is the `ptr` argument described previously). We still must `return` or else we would actually jump to 3 bytes after the `ptr` battle script begins.
=======
To preface this tutorial, the battle engine upgrade has exhausted all battle script command IDs. Historically, we've used the `various` command to effectively add new commands. However, this has caused issues of maintainability and readability due to the massive switch needed for it. Thanks to the cleanup made by the team and contributors, we now are able to call an infinite amount of commands by using `callnative`. This is preferential to creating a secondary battle script command table like is done in the CFRU.

In general, `gBattlescriptCurrInstr` tracks the current battle script position as a ROM address. Fortunately, we don't need to worry about ROM addresses when using the decomps, but it is important to understand because of how the `callnative` command is set up.

```
	.macro callnative func:req
	.byte 0xff
	.4byte \func
	.endm
```
`callnative` uses the last battle script command ID in order to pass a native function as an argument. Additional optional arguments are added recursively via a macro, so no need to worry about how they need to align to the amount of instructions to skip.

Now, how might we add a custom `callnative` command? Here are the steps. We will use `BS_TrySetOctolock` as an example.
### 1. Create a macro in `asm/macros/battle_script.inc`. For example:
```c
	.macro trysetoctolock battler:req, failInstr:req
	callnative BS_TrySetOctolock
	.byte \battler
	.4byte \failInstr
	.endm
```
### 2. Add your new callnative command ID to `src/battle_script_commands.c`. For example:
```c
void BS_TrySetOctolock(void)
{
    NATIVE_ARGS(u8 battler, const u8 *failInstr);
    u32 battler = GetBattlerForBattleScript(cmd->battler);

    if (gDisableStructs[battler].octolock)
    {
        gBattlescriptCurrInstr = cmd->failInstr;
    }
    else
    {
        gDisableStructs[battler].octolock = TRUE;
        gBattleMons[battler].status2 |= STATUS2_ESCAPE_PREVENTION;
        gDisableStructs[battler].battlerPreventingEscape = gBattlerAttacker;
        gBattlescriptCurrInstr = cmd->nextInstr;
    }
}
```
Each of the arguments defined in the macro (`battler`, `failInstr`) need to be called at the start of the command using `NATIVE_ARGS`.
The byte count in the macro should correspond to the type that will be used for the command (eg, `u8` is `byte`, while the pointer are `4byte`).
These arguments can then be accessed as `cmd->battler` and `cmd->battler`.
`gBattlescriptCurrInstr = cmd->nextInstr;` advances to the next instruction.
>>>>>>> upstream/master
