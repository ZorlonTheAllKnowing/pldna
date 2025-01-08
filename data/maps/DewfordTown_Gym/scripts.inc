<<<<<<< HEAD
# 1 "data/maps/DewfordTown_Gym/scripts.pory"

# 2 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_MapScripts::
# 3 "data/maps/DewfordTown_Gym/scripts.pory"
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_Gym_OnTransition
# 4 "data/maps/DewfordTown_Gym/scripts.pory"
	.byte 0
# 5 "data/maps/DewfordTown_Gym/scripts.pory"

# 6 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_OnTransition:
# 7 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashLevel
# 8 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 9 "data/maps/DewfordTown_Gym/scripts.pory"

# 10 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashLevel::
# 11 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_defeated TRAINER_BRAWLY_1, DewfordTown_Gym_EventScript_SetLightsOn
# 12 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
# 13 "data/maps/DewfordTown_Gym/scripts.pory"
	copyvar VAR_0x8001, VAR_0x8000
# 14 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 0, DewfordTown_Gym_EventScript_SetFlashLevel7
# 15 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_SetFlashLevel6
# 16 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_SetFlashLevel5
# 17 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_SetFlashLevel4
# 18 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_SetFlashLevel3
# 19 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_SetFlashLevel2
# 20 "data/maps/DewfordTown_Gym/scripts.pory"
	goto DewfordTown_Gym_EventScript_SetFlashLevel1
# 21 "data/maps/DewfordTown_Gym/scripts.pory"

# 22 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetLightsOn::
# 23 "data/maps/DewfordTown_Gym/scripts.pory"
	setflashlevel 0
# 24 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 25 "data/maps/DewfordTown_Gym/scripts.pory"

# 26 "data/maps/DewfordTown_Gym/scripts.pory"
@ Brightest
# 27 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashLevel1::
# 28 "data/maps/DewfordTown_Gym/scripts.pory"
	setflashlevel 1
# 29 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 30 "data/maps/DewfordTown_Gym/scripts.pory"

# 31 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashLevel2::
# 32 "data/maps/DewfordTown_Gym/scripts.pory"
	setflashlevel 2
# 33 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 34 "data/maps/DewfordTown_Gym/scripts.pory"

# 35 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashLevel3::
# 36 "data/maps/DewfordTown_Gym/scripts.pory"
	setflashlevel 3
# 37 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 38 "data/maps/DewfordTown_Gym/scripts.pory"

# 39 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashLevel4::
# 40 "data/maps/DewfordTown_Gym/scripts.pory"
	setflashlevel 4
# 41 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 42 "data/maps/DewfordTown_Gym/scripts.pory"

# 43 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashLevel5::
# 44 "data/maps/DewfordTown_Gym/scripts.pory"
	setflashlevel 5
# 45 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 46 "data/maps/DewfordTown_Gym/scripts.pory"

# 47 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashLevel6::
# 48 "data/maps/DewfordTown_Gym/scripts.pory"
	setflashlevel 6
# 49 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 50 "data/maps/DewfordTown_Gym/scripts.pory"

# 51 "data/maps/DewfordTown_Gym/scripts.pory"
@ Darkest
# 52 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_SetFlashLevel7::
# 53 "data/maps/DewfordTown_Gym/scripts.pory"
	setflashlevel 7
# 54 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 55 "data/maps/DewfordTown_Gym/scripts.pory"

# 56 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_BrightenRoom::
# 57 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
# 58 "data/maps/DewfordTown_Gym/scripts.pory"
	nop1
# 59 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, VAR_0x8001, DewfordTown_Gym_EventScript_NoLightChange
# 60 "data/maps/DewfordTown_Gym/scripts.pory"
	copyvar VAR_0x8001, VAR_0x8000
# 61 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_AnimateFlash1Trainer
# 62 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_AnimateFlash2Trainers
# 63 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_AnimateFlash3Trainers
# 64 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_AnimateFlash4Trainers
# 65 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_AnimateFlash5Trainers
# 66 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_0x8000, 6, DewfordTown_Gym_EventScript_AnimateFlash6Trainers
# 67 "data/maps/DewfordTown_Gym/scripts.pory"

# 68 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_NoLightChange::
# 69 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 70 "data/maps/DewfordTown_Gym/scripts.pory"

# 71 "data/maps/DewfordTown_Gym/scripts.pory"
@ NOTE: A little confusingly, a larger animateflash param value is a smaller flash radius
# 72 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_AnimateFlash1Trainer::
# 73 "data/maps/DewfordTown_Gym/scripts.pory"
	playse SE_SWITCH
# 74 "data/maps/DewfordTown_Gym/scripts.pory"
	animateflash 6
# 75 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashLevel
# 76 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 77 "data/maps/DewfordTown_Gym/scripts.pory"

# 78 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_AnimateFlash2Trainers::
# 79 "data/maps/DewfordTown_Gym/scripts.pory"
	playse SE_SWITCH
# 80 "data/maps/DewfordTown_Gym/scripts.pory"
	animateflash 5
# 81 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashLevel
# 82 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 83 "data/maps/DewfordTown_Gym/scripts.pory"

# 84 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_AnimateFlash3Trainers::
# 85 "data/maps/DewfordTown_Gym/scripts.pory"
	playse SE_SWITCH
# 86 "data/maps/DewfordTown_Gym/scripts.pory"
	animateflash 4
# 87 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashLevel
# 88 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 89 "data/maps/DewfordTown_Gym/scripts.pory"

# 90 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_AnimateFlash4Trainers::
# 91 "data/maps/DewfordTown_Gym/scripts.pory"
	playse SE_SWITCH
# 92 "data/maps/DewfordTown_Gym/scripts.pory"
	animateflash 3
# 93 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashLevel
# 94 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 95 "data/maps/DewfordTown_Gym/scripts.pory"

# 96 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_AnimateFlash5Trainers::
# 97 "data/maps/DewfordTown_Gym/scripts.pory"
	playse SE_SWITCH
# 98 "data/maps/DewfordTown_Gym/scripts.pory"
	animateflash 2
# 99 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashLevel
# 100 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 101 "data/maps/DewfordTown_Gym/scripts.pory"

# 102 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_AnimateFlash6Trainers::
# 103 "data/maps/DewfordTown_Gym/scripts.pory"
	playse SE_SWITCH
# 104 "data/maps/DewfordTown_Gym/scripts.pory"
	animateflash 1
# 105 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashLevel
# 106 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 107 "data/maps/DewfordTown_Gym/scripts.pory"

# 108 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_AnimateFlashFullBrightness::
# 109 "data/maps/DewfordTown_Gym/scripts.pory"
	playse SE_SWITCH
# 110 "data/maps/DewfordTown_Gym/scripts.pory"
	animateflash 0
# 111 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_SetFlashLevel
# 112 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 113 "data/maps/DewfordTown_Gym/scripts.pory"

# 114 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_CountTrainersDefeated::
# 115 "data/maps/DewfordTown_Gym/scripts.pory"
	setvar VAR_0x8000, 0
# 116 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_TAKAO, DewfordTown_Gym_EventScript_CheckJocelyn
# 117 "data/maps/DewfordTown_Gym/scripts.pory"
	addvar VAR_0x8000, 1
# 118 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_CheckJocelyn::
# 119 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_JOCELYN, DewfordTown_Gym_EventScript_CheckLaura
# 120 "data/maps/DewfordTown_Gym/scripts.pory"
	addvar VAR_0x8000, 1
# 121 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_CheckLaura::
# 122 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_LAURA, DewfordTown_Gym_EventScript_CheckBrenden
# 123 "data/maps/DewfordTown_Gym/scripts.pory"
	addvar VAR_0x8000, 1
# 124 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_CheckBrenden::
# 125 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_BRENDEN, DewfordTown_Gym_EventScript_CheckCristian
# 126 "data/maps/DewfordTown_Gym/scripts.pory"
	addvar VAR_0x8000, 1
# 127 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_CheckCristian::
# 128 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_CRISTIAN, DewfordTown_Gym_EventScript_CheckLilith
# 129 "data/maps/DewfordTown_Gym/scripts.pory"
	addvar VAR_0x8000, 1
# 130 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_CheckLilith::
# 131 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_not_defeated TRAINER_LILITH, DewfordTown_Gym_EventScript_StopCountingTrainers
# 132 "data/maps/DewfordTown_Gym/scripts.pory"
	addvar VAR_0x8000, 1
# 133 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_StopCountingTrainers::
# 134 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 135 "data/maps/DewfordTown_Gym/scripts.pory"

# 136 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_Brawly::
# 137 "data/maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyIntro, DewfordTown_Gym_Text_BrawlyDefeat, DewfordTown_Gym_EventScript_BrawlyDefeated, NO_MUSIC
# 138 "data/maps/DewfordTown_Gym/scripts.pory"
	specialvar VAR_RESULT, ShouldTryRematchBattle
# 139 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Gym_EventScript_BrawlyRematch
# 140 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_unset FLAG_RECEIVED_TM_BULK_UP, DewfordTown_Gym_EventScript_GiveBulkUp2
# 141 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_BrawlyPostBattle, MSGBOX_DEFAULT
# 142 "data/maps/DewfordTown_Gym/scripts.pory"
	release
# 143 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 144 "data/maps/DewfordTown_Gym/scripts.pory"

# 145 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_BrawlyDefeated::
# 146 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_AnimateFlashFullBrightness
# 147 "data/maps/DewfordTown_Gym/scripts.pory"
	message DewfordTown_Gym_Text_ReceivedKnuckleBadge
# 148 "data/maps/DewfordTown_Gym/scripts.pory"
	waitmessage
# 149 "data/maps/DewfordTown_Gym/scripts.pory"
	call Common_EventScript_PlayGymBadgeFanfare
# 150 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis, MSGBOX_DEFAULT
# 151 "data/maps/DewfordTown_Gym/scripts.pory"
	setflag FLAG_DEFEATED_DEWFORD_GYM
# 152 "data/maps/DewfordTown_Gym/scripts.pory"
	setflag FLAG_BADGE02_GET
# 153 "data/maps/DewfordTown_Gym/scripts.pory"
	addvar VAR_PETALBURG_GYM_STATE, 1
# 154 "data/maps/DewfordTown_Gym/scripts.pory"
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
# 155 "data/maps/DewfordTown_Gym/scripts.pory"
	setvar VAR_0x8008, 2
# 156 "data/maps/DewfordTown_Gym/scripts.pory"
	call Common_EventScript_SetGymTrainers
# 157 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_GiveBulkUp
# 158 "data/maps/DewfordTown_Gym/scripts.pory"
	closemessage
# 159 "data/maps/DewfordTown_Gym/scripts.pory"
	delay 30
# 160 "data/maps/DewfordTown_Gym/scripts.pory"
	playfanfare MUS_REGISTER_MATCH_CALL
# 161 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_RegisteredBrawly, MSGBOX_DEFAULT
# 162 "data/maps/DewfordTown_Gym/scripts.pory"
	waitfanfare
# 163 "data/maps/DewfordTown_Gym/scripts.pory"
	closemessage
# 164 "data/maps/DewfordTown_Gym/scripts.pory"
	delay 30
# 165 "data/maps/DewfordTown_Gym/scripts.pory"
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
# 166 "data/maps/DewfordTown_Gym/scripts.pory"
	setvar VAR_ROXANNE_CALL_STEP_COUNTER, 0
# 167 "data/maps/DewfordTown_Gym/scripts.pory"
	setflag FLAG_ENABLE_ROXANNE_FIRST_CALL
# 168 "data/maps/DewfordTown_Gym/scripts.pory"
	release
# 169 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 170 "data/maps/DewfordTown_Gym/scripts.pory"

# 171 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_GiveBulkUp::
# 172 "data/maps/DewfordTown_Gym/scripts.pory"
	giveitem ITEM_TM_BULK_UP
# 173 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
# 174 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
# 175 "data/maps/DewfordTown_Gym/scripts.pory"
	setflag FLAG_RECEIVED_TM_BULK_UP
# 176 "data/maps/DewfordTown_Gym/scripts.pory"
	return
# 177 "data/maps/DewfordTown_Gym/scripts.pory"

# 178 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_GiveBulkUp2:
# 179 "data/maps/DewfordTown_Gym/scripts.pory"
	giveitem ITEM_TM_BULK_UP
# 180 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
# 181 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
# 182 "data/maps/DewfordTown_Gym/scripts.pory"
	setflag FLAG_RECEIVED_TM_BULK_UP
# 183 "data/maps/DewfordTown_Gym/scripts.pory"
	release
# 184 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 185 "data/maps/DewfordTown_Gym/scripts.pory"

# 186 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_BrawlyRematch::
# 187 "data/maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_rematch_double TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyPreRematch, DewfordTown_Gym_Text_BrawlyRematchDefeat, DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons
# 188 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_BrawlyPostRematch, MSGBOX_AUTOCLOSE
# 189 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 190 "data/maps/DewfordTown_Gym/scripts.pory"

# 191 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_Takao::
# 192 "data/maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_TAKAO, DewfordTown_Gym_Text_TakaoIntro, DewfordTown_Gym_Text_TakaoDefeat, DewfordTown_Gym_EventScript_TakaoBrightenRoom
# 193 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_TakaoPostBattle, MSGBOX_AUTOCLOSE
# 194 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 195 "data/maps/DewfordTown_Gym/scripts.pory"

# 196 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_TakaoBrightenRoom::
# 197 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_BrightenRoom
# 198 "data/maps/DewfordTown_Gym/scripts.pory"
	release
# 199 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 200 "data/maps/DewfordTown_Gym/scripts.pory"

# 201 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_Jocelyn::
# 202 "data/maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_JOCELYN, DewfordTown_Gym_Text_JocelynIntro, DewfordTown_Gym_Text_JocelynDefeat, DewfordTown_Gym_EventScript_JocelynBrightenRoom
# 203 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
# 204 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 205 "data/maps/DewfordTown_Gym/scripts.pory"

# 206 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_JocelynBrightenRoom::
# 207 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_BrightenRoom
# 208 "data/maps/DewfordTown_Gym/scripts.pory"
	release
# 209 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 210 "data/maps/DewfordTown_Gym/scripts.pory"

# 211 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_Laura::
# 212 "data/maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_LAURA, DewfordTown_Gym_Text_LauraIntro, DewfordTown_Gym_Text_LauraDefeat, DewfordTown_Gym_EventScript_LauraBrightenRoom
# 213 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
# 214 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 215 "data/maps/DewfordTown_Gym/scripts.pory"

# 216 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_LauraBrightenRoom::
# 217 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_BrightenRoom
# 218 "data/maps/DewfordTown_Gym/scripts.pory"
	release
# 219 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 220 "data/maps/DewfordTown_Gym/scripts.pory"

# 221 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_Brenden::
# 222 "data/maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_BRENDEN, DewfordTown_Gym_Text_BrendenIntro, DewfordTown_Gym_Text_BrendenDefeat, DewfordTown_Gym_EventScript_BrendenBrightenRoom
# 223 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_BrendenPostBattle, MSGBOX_AUTOCLOSE
# 224 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 225 "data/maps/DewfordTown_Gym/scripts.pory"

# 226 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_BrendenBrightenRoom::
# 227 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_BrightenRoom
# 228 "data/maps/DewfordTown_Gym/scripts.pory"
	release
# 229 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 230 "data/maps/DewfordTown_Gym/scripts.pory"

# 231 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_Cristian::
# 232 "data/maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_CRISTIAN, DewfordTown_Gym_Text_CristianIntro, DewfordTown_Gym_Text_CristianDefeat, DewfordTown_Gym_EventScript_CristianBrightenRoom
# 233 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_CristianPostBattle, MSGBOX_AUTOCLOSE
# 234 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 235 "data/maps/DewfordTown_Gym/scripts.pory"

# 236 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_CristianBrightenRoom::
# 237 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_BrightenRoom
# 238 "data/maps/DewfordTown_Gym/scripts.pory"
	release
# 239 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 240 "data/maps/DewfordTown_Gym/scripts.pory"

# 241 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_Lilith::
# 242 "data/maps/DewfordTown_Gym/scripts.pory"
	trainerbattle_single TRAINER_LILITH, DewfordTown_Gym_Text_LilithIntro, DewfordTown_Gym_Text_LilithDefeat, DewfordTown_Gym_EventScript_LilithBrightenRoom
# 243 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_LilithPostBattle, MSGBOX_AUTOCLOSE
# 244 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 245 "data/maps/DewfordTown_Gym/scripts.pory"

# 246 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_LilithBrightenRoom::
# 247 "data/maps/DewfordTown_Gym/scripts.pory"
	call DewfordTown_Gym_EventScript_BrightenRoom
# 248 "data/maps/DewfordTown_Gym/scripts.pory"
	release
# 249 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 250 "data/maps/DewfordTown_Gym/scripts.pory"

# 251 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_GymGuide::
# 252 "data/maps/DewfordTown_Gym/scripts.pory"
	lock
# 253 "data/maps/DewfordTown_Gym/scripts.pory"
	faceplayer
# 254 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_set FLAG_DEFEATED_DEWFORD_GYM, DewfordTown_Gym_EventScript_GymGuidePostVictory
# 255 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
# 256 "data/maps/DewfordTown_Gym/scripts.pory"
	release
# 257 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 258 "data/maps/DewfordTown_Gym/scripts.pory"

# 259 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_GymGuidePostVictory::
# 260 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
# 261 "data/maps/DewfordTown_Gym/scripts.pory"
	release
# 262 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 263 "data/maps/DewfordTown_Gym/scripts.pory"

# 264 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_LeftGymStatue::
# 265 "data/maps/DewfordTown_Gym/scripts.pory"
	lockall
# 266 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
# 267 "data/maps/DewfordTown_Gym/scripts.pory"
	goto DewfordTown_Gym_EventScript_GymStatue
# 268 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 269 "data/maps/DewfordTown_Gym/scripts.pory"

# 270 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_RightGymStatue::
# 271 "data/maps/DewfordTown_Gym/scripts.pory"
	lockall
# 272 "data/maps/DewfordTown_Gym/scripts.pory"
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
# 273 "data/maps/DewfordTown_Gym/scripts.pory"
	goto DewfordTown_Gym_EventScript_GymStatue
# 274 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 275 "data/maps/DewfordTown_Gym/scripts.pory"

# 276 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_GymStatueCertified::
# 277 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
# 278 "data/maps/DewfordTown_Gym/scripts.pory"
	releaseall
# 279 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 280 "data/maps/DewfordTown_Gym/scripts.pory"

# 281 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_EventScript_GymStatue::
# 282 "data/maps/DewfordTown_Gym/scripts.pory"
	msgbox DewfordTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
# 283 "data/maps/DewfordTown_Gym/scripts.pory"
	releaseall
# 284 "data/maps/DewfordTown_Gym/scripts.pory"
	end
# 285 "data/maps/DewfordTown_Gym/scripts.pory"

# 286 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_GymGuideAdvice:
# 287 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Hey, how's it going, CHAMPION-\n"
# 288 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "bound {PLAYER}?\p"
# 289 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "DEWFORD's GYM LEADER BRAWLY commands\n"
# 290 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "FIGHTING-type POKéMON.\p"
# 291 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Going against him with NORMAL-type\n"
# 292 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "POKéMON is asking for trouble.\p"
# 293 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "FIGHTING POKéMON will lay a serious\n"
# 294 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "smack down on NORMAL POKéMON,\l"
# 295 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "so be careful!\p"
# 296 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "What's worse, the GYM is as dark as\n"
# 297 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "the ocean floor.\p"
# 298 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "But it will get brighter after defeating\n"
# 299 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "the TRAINERS in your way.\p"
# 300 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Hey, okay, go for it!$"
# 301 "data/maps/DewfordTown_Gym/scripts.pory"

# 302 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_GymGuidePostVictory:
# 303 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Whoah! It's turned too bright in here!\p"
# 304 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Your future is bright, too!$"
# 305 "data/maps/DewfordTown_Gym/scripts.pory"

# 306 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_TakaoIntro:
# 307 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Might is right!\n"
# 308 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Come on!$"
# 309 "data/maps/DewfordTown_Gym/scripts.pory"

# 310 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_TakaoDefeat:
# 311 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Not enough power…$"
# 312 "data/maps/DewfordTown_Gym/scripts.pory"

# 313 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_TakaoPostBattle:
# 314 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Your skill overcame my strength!\n"
# 315 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Your technique is commendable!$"
# 316 "data/maps/DewfordTown_Gym/scripts.pory"

# 317 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_JocelynIntro:
# 318 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "There's no need for BRAWLY to be\n"
# 319 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "involved!\p"
# 320 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I'll crush you!$"
# 321 "data/maps/DewfordTown_Gym/scripts.pory"

# 322 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_JocelynDefeat:
# 323 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "But… How?\n"
# 324 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "How could I lose so easily?$"
# 325 "data/maps/DewfordTown_Gym/scripts.pory"

# 326 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_JocelynPostBattle:
# 327 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I'm not going to waste this loss.\n"
# 328 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I'll use it to motivate me to train!\p"
# 329 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "One day I'll become a GYM LEADER…\p"
# 330 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "No, I'll become the POKéMON LEAGUE\n"
# 331 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "CHAMPION!$"
# 332 "data/maps/DewfordTown_Gym/scripts.pory"

# 333 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_LauraIntro:
# 334 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Don't you dare brush me off!\n"
# 335 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "It's not my fault if you cry!$"
# 336 "data/maps/DewfordTown_Gym/scripts.pory"

# 337 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_LauraDefeat:
# 338 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Waaaaaaah!\n"
# 339 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I lost!$"
# 340 "data/maps/DewfordTown_Gym/scripts.pory"

# 341 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_LauraPostBattle:
# 342 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I battle in the dark to make my heart\n"
# 343 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "stronger.\p"
# 344 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "But because it's so dark, I can never\n"
# 345 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "see BRAWLY's face…$"
# 346 "data/maps/DewfordTown_Gym/scripts.pory"

# 347 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_LilithIntro:
# 348 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Ufufu…\n"
# 349 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Are you stumbling around in the dark?$"
# 350 "data/maps/DewfordTown_Gym/scripts.pory"

# 351 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_LilithDefeat:
# 352 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Oh, you…\n"
# 353 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I don't want to know you!$"
# 354 "data/maps/DewfordTown_Gym/scripts.pory"

# 355 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_LilithPostBattle:
# 356 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "You deserve to stay lost and end up\n"
# 357 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "back at the entrance again!$"
# 358 "data/maps/DewfordTown_Gym/scripts.pory"

# 359 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrendenIntro:
# 360 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I'll show you the gumption of\n"
# 361 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "a sailing man!$"
# 362 "data/maps/DewfordTown_Gym/scripts.pory"

# 363 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrendenDefeat:
# 364 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "How'd this happen?\n"
# 365 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "It's not like me to lose this way!$"
# 366 "data/maps/DewfordTown_Gym/scripts.pory"

# 367 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrendenPostBattle:
# 368 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Oh, aye! You're worthy of seeing\n"
# 369 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "our GYM LEADER.$"
# 370 "data/maps/DewfordTown_Gym/scripts.pory"

# 371 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_CristianIntro:
# 372 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "If you mean to pass, it has to be\n"
# 373 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "through me!$"
# 374 "data/maps/DewfordTown_Gym/scripts.pory"

# 375 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_CristianDefeat:
# 376 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Grrrrr!\n"
# 377 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Vastly overpowered!$"
# 378 "data/maps/DewfordTown_Gym/scripts.pory"

# 379 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_CristianPostBattle:
# 380 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "You win!\n"
# 381 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Go after that BADGE!$"
# 382 "data/maps/DewfordTown_Gym/scripts.pory"

# 383 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrawlyIntro:
# 384 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I'm BRAWLY!\n"
# 385 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "DEWFORD's GYM LEADER!\p"
# 386 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I've been churned in the rough waves\n"
# 387 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "of these parts, and I've grown tough\l"
# 388 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "in the pitch-black cave!\p"
# 389 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "So you wanted to challenge me?\n"
# 390 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Let me see what you're made of!$"
# 391 "data/maps/DewfordTown_Gym/scripts.pory"

# 392 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrawlyDefeat:
# 393 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Whoah, wow! You made a much bigger\n"
# 394 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "splash than I expected!\p"
# 395 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "You swamped me!\p"
# 396 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Okay, you've got me.\n"
# 397 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Take this GYM BADGE!$"
# 398 "data/maps/DewfordTown_Gym/scripts.pory"

# 399 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_ReceivedKnuckleBadge:
# 400 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "{PLAYER} received the KNUCKLE BADGE\n"
# 401 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "from BRAWLY.$"
# 402 "data/maps/DewfordTown_Gym/scripts.pory"

# 403 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis:
# 404 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "The KNUCKLE BADGE makes all POKéMON\n"
# 405 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "up to Level 30, even those you get in\l"
# 406 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "trades, obey without question.\p"
# 407 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "And, you'll be able to use the HM move\n"
# 408 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "FLASH outside of battle.\p"
# 409 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "If you'd like, use this TECHNICAL\n"
# 410 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "MACHINE, too.$"
# 411 "data/maps/DewfordTown_Gym/scripts.pory"

# 412 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_ExplainBulkUp:
# 413 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "That TM08 contains BULK UP.\p"
# 414 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "It's a move that raises both ATTACK\n"
# 415 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "and DEFENSE stats.\p"
# 416 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "… … … … … …$"
# 417 "data/maps/DewfordTown_Gym/scripts.pory"

# 418 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_RegisteredBrawly:
# 419 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Registered GYM LEADER BRAWLY\n"
# 420 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "in the POKéNAV.$"
# 421 "data/maps/DewfordTown_Gym/scripts.pory"

# 422 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrawlyPostBattle:
# 423 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I can see your talent becoming a giant\n"
# 424 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "wave to cause a storm of astonishment\l"
# 425 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "among TRAINERS one day!$"
# 426 "data/maps/DewfordTown_Gym/scripts.pory"

# 427 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_GymStatue:
# 428 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "DEWFORD TOWN POKéMON GYM$"
# 429 "data/maps/DewfordTown_Gym/scripts.pory"

# 430 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_GymStatueCertified:
# 431 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "DEWFORD TOWN POKéMON GYM\p"
# 432 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "BRAWLY'S CERTIFIED TRAINERS:\n"
# 433 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "{PLAYER}$"
# 434 "data/maps/DewfordTown_Gym/scripts.pory"

# 435 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrawlyPreRematch:
# 436 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "BRAWLY: A wave may draw back, but it\n"
# 437 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "always returns to the shore.\p"
# 438 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "A giant wave of a talent like you…\n"
# 439 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I knew you would return!\p"
# 440 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Show me how much higher\n"
# 441 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "you've gone!$"
# 442 "data/maps/DewfordTown_Gym/scripts.pory"

# 443 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrawlyRematchDefeat:
# 444 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Wow!\n"
# 445 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Swamped again!$"
# 446 "data/maps/DewfordTown_Gym/scripts.pory"

# 447 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrawlyPostRematch:
# 448 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "BRAWLY: Battling is vast and it's deep.\n"
# 449 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "You can't see the bottom.\l"
# 450 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "It's just like the sea of HOENN!$"
# 451 "data/maps/DewfordTown_Gym/scripts.pory"

# 452 "data/maps/DewfordTown_Gym/scripts.pory"
DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons:
# 453 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "BRAWLY: A wave may draw back, but it\n"
# 454 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "always returns to the shore.\p"
# 455 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "A giant wave of a talent like you…\n"
# 456 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I knew you would return!\p"
# 457 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "Oh? You only have one POKéMON\n"
# 458 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "that can battle.\p"
# 459 "data/maps/DewfordTown_Gym/scripts.pory"
	.string "I'm sorry, but I'd like you to come back\n"
# 460 "data/maps/DewfordTown_Gym/scripts.pory"
=======
DewfordTown_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, DewfordTown_Gym_OnTransition
	.byte 0

DewfordTown_Gym_OnTransition:
	call DewfordTown_Gym_EventScript_SetFlashLevel
	end

DewfordTown_Gym_EventScript_SetFlashLevel::
	goto_if_defeated TRAINER_BRAWLY_1, DewfordTown_Gym_EventScript_SetLightsOn
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 0, DewfordTown_Gym_EventScript_SetFlashLevel7
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_SetFlashLevel6
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_SetFlashLevel5
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_SetFlashLevel4
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_SetFlashLevel3
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_SetFlashLevel2
	goto DewfordTown_Gym_EventScript_SetFlashLevel1

DewfordTown_Gym_EventScript_SetLightsOn::
	setflashlevel 0
	return

@ Brightest
DewfordTown_Gym_EventScript_SetFlashLevel1::
	setflashlevel 1
	return

DewfordTown_Gym_EventScript_SetFlashLevel2::
	setflashlevel 2
	return

DewfordTown_Gym_EventScript_SetFlashLevel3::
	setflashlevel 3
	return

DewfordTown_Gym_EventScript_SetFlashLevel4::
	setflashlevel 4
	return

DewfordTown_Gym_EventScript_SetFlashLevel5::
	setflashlevel 5
	return

DewfordTown_Gym_EventScript_SetFlashLevel6::
	setflashlevel 6
	return

@ Darkest
DewfordTown_Gym_EventScript_SetFlashLevel7::
	setflashlevel 7
	return

DewfordTown_Gym_EventScript_BrightenRoom::
	call DewfordTown_Gym_EventScript_CountTrainersDefeated
	nop1
	goto_if_eq VAR_0x8000, VAR_0x8001, DewfordTown_Gym_EventScript_NoLightChange
	copyvar VAR_0x8001, VAR_0x8000
	goto_if_eq VAR_0x8000, 1, DewfordTown_Gym_EventScript_AnimateFlash1Trainer
	goto_if_eq VAR_0x8000, 2, DewfordTown_Gym_EventScript_AnimateFlash2Trainers
	goto_if_eq VAR_0x8000, 3, DewfordTown_Gym_EventScript_AnimateFlash3Trainers
	goto_if_eq VAR_0x8000, 4, DewfordTown_Gym_EventScript_AnimateFlash4Trainers
	goto_if_eq VAR_0x8000, 5, DewfordTown_Gym_EventScript_AnimateFlash5Trainers
	goto_if_eq VAR_0x8000, 6, DewfordTown_Gym_EventScript_AnimateFlash6Trainers

DewfordTown_Gym_EventScript_NoLightChange::
	return

@ NOTE: A little confusingly, a larger animateflash param value is a smaller flash radius
DewfordTown_Gym_EventScript_AnimateFlash1Trainer::
	playse SE_SWITCH
	animateflash 6
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash2Trainers::
	playse SE_SWITCH
	animateflash 5
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash3Trainers::
	playse SE_SWITCH
	animateflash 4
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash4Trainers::
	playse SE_SWITCH
	animateflash 3
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash5Trainers::
	playse SE_SWITCH
	animateflash 2
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlash6Trainers::
	playse SE_SWITCH
	animateflash 1
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_AnimateFlashFullBrightness::
	playse SE_SWITCH
	animateflash 0
	call DewfordTown_Gym_EventScript_SetFlashLevel
	return

DewfordTown_Gym_EventScript_CountTrainersDefeated::
	setvar VAR_0x8000, 0
	goto_if_not_defeated TRAINER_TAKAO, DewfordTown_Gym_EventScript_CheckJocelyn
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckJocelyn::
	goto_if_not_defeated TRAINER_JOCELYN, DewfordTown_Gym_EventScript_CheckLaura
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLaura::
	goto_if_not_defeated TRAINER_LAURA, DewfordTown_Gym_EventScript_CheckBrenden
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckBrenden::
	goto_if_not_defeated TRAINER_BRENDEN, DewfordTown_Gym_EventScript_CheckCristian
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckCristian::
	goto_if_not_defeated TRAINER_CRISTIAN, DewfordTown_Gym_EventScript_CheckLilith
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_CheckLilith::
	goto_if_not_defeated TRAINER_LILITH, DewfordTown_Gym_EventScript_StopCountingTrainers
	addvar VAR_0x8000, 1
DewfordTown_Gym_EventScript_StopCountingTrainers::
	return

DewfordTown_Gym_EventScript_Brawly::
	trainerbattle_single TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyIntro, DewfordTown_Gym_Text_BrawlyDefeat, DewfordTown_Gym_EventScript_BrawlyDefeated, NO_MUSIC
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, DewfordTown_Gym_EventScript_BrawlyRematch
	goto_if_unset FLAG_RECEIVED_TM_BULK_UP, DewfordTown_Gym_EventScript_GiveBulkUp2
	msgbox DewfordTown_Gym_Text_BrawlyPostBattle, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_BrawlyDefeated::
	call DewfordTown_Gym_EventScript_AnimateFlashFullBrightness
	message DewfordTown_Gym_Text_ReceivedKnuckleBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_DEWFORD_GYM
	setflag FLAG_BADGE02_GET
	addvar VAR_PETALBURG_GYM_STATE, 1
	call_if_eq VAR_PETALBURG_GYM_STATE, 6, Common_EventScript_ReadyPetalburgGymForBattle
	setvar VAR_0x8008, 2
	call Common_EventScript_SetGymTrainers
	call DewfordTown_Gym_EventScript_GiveBulkUp
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox DewfordTown_Gym_Text_RegisteredBrawly, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	setflag FLAG_ENABLE_BRAWLY_MATCH_CALL
	setvar VAR_ROXANNE_CALL_STEP_COUNTER, 0
	setflag FLAG_ENABLE_ROXANNE_FIRST_CALL
	release
	end

DewfordTown_Gym_EventScript_GiveBulkUp::
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_BagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	return

DewfordTown_Gym_EventScript_GiveBulkUp2:
	giveitem ITEM_TM_BULK_UP
	goto_if_eq VAR_RESULT, 0, Common_EventScript_ShowBagIsFull
	msgbox DewfordTown_Gym_Text_ExplainBulkUp, MSGBOX_DEFAULT
	setflag FLAG_RECEIVED_TM_BULK_UP
	release
	end

DewfordTown_Gym_EventScript_BrawlyRematch::
	trainerbattle_rematch_double TRAINER_BRAWLY_1, DewfordTown_Gym_Text_BrawlyPreRematch, DewfordTown_Gym_Text_BrawlyRematchDefeat, DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons
	msgbox DewfordTown_Gym_Text_BrawlyPostRematch, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_Takao::
	trainerbattle_single TRAINER_TAKAO, DewfordTown_Gym_Text_TakaoIntro, DewfordTown_Gym_Text_TakaoDefeat, DewfordTown_Gym_EventScript_TakaoBrightenRoom
	msgbox DewfordTown_Gym_Text_TakaoPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_TakaoBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Jocelyn::
	trainerbattle_single TRAINER_JOCELYN, DewfordTown_Gym_Text_JocelynIntro, DewfordTown_Gym_Text_JocelynDefeat, DewfordTown_Gym_EventScript_JocelynBrightenRoom
	msgbox DewfordTown_Gym_Text_JocelynPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_JocelynBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Laura::
	trainerbattle_single TRAINER_LAURA, DewfordTown_Gym_Text_LauraIntro, DewfordTown_Gym_Text_LauraDefeat, DewfordTown_Gym_EventScript_LauraBrightenRoom
	msgbox DewfordTown_Gym_Text_LauraPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LauraBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Brenden::
	trainerbattle_single TRAINER_BRENDEN, DewfordTown_Gym_Text_BrendenIntro, DewfordTown_Gym_Text_BrendenDefeat, DewfordTown_Gym_EventScript_BrendenBrightenRoom
	msgbox DewfordTown_Gym_Text_BrendenPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_BrendenBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Cristian::
	trainerbattle_single TRAINER_CRISTIAN, DewfordTown_Gym_Text_CristianIntro, DewfordTown_Gym_Text_CristianDefeat, DewfordTown_Gym_EventScript_CristianBrightenRoom
	msgbox DewfordTown_Gym_Text_CristianPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_CristianBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_Lilith::
	trainerbattle_single TRAINER_LILITH, DewfordTown_Gym_Text_LilithIntro, DewfordTown_Gym_Text_LilithDefeat, DewfordTown_Gym_EventScript_LilithBrightenRoom
	msgbox DewfordTown_Gym_Text_LilithPostBattle, MSGBOX_AUTOCLOSE
	end

DewfordTown_Gym_EventScript_LilithBrightenRoom::
	call DewfordTown_Gym_EventScript_BrightenRoom
	release
	end

DewfordTown_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_DEWFORD_GYM, DewfordTown_Gym_EventScript_GymGuidePostVictory
	msgbox DewfordTown_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_GymGuidePostVictory::
	msgbox DewfordTown_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

DewfordTown_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, DewfordTown_Gym_EventScript_GymStatueCertified
	goto DewfordTown_Gym_EventScript_GymStatue
	end

DewfordTown_Gym_EventScript_GymStatueCertified::
	msgbox DewfordTown_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_EventScript_GymStatue::
	msgbox DewfordTown_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

DewfordTown_Gym_Text_GymGuideAdvice:
	.string "Hey, how's it going, CHAMPION-\n"
	.string "bound {PLAYER}?\p"
	.string "DEWFORD's GYM LEADER BRAWLY commands\n"
	.string "FIGHTING-type POKéMON.\p"
	.string "Going against him with NORMAL-type\n"
	.string "POKéMON is asking for trouble.\p"
	.string "FIGHTING POKéMON will lay a serious\n"
	.string "smack down on NORMAL POKéMON,\l"
	.string "so be careful!\p"
	.string "What's worse, the GYM is as dark as\n"
	.string "the ocean floor.\p"
	.string "But it will get brighter after defeating\n"
	.string "the TRAINERS in your way.\p"
	.string "Hey, okay, go for it!$"

DewfordTown_Gym_Text_GymGuidePostVictory:
	.string "Whoah! It's turned too bright in here!\p"
	.string "Your future is bright, too!$"

DewfordTown_Gym_Text_TakaoIntro:
	.string "Might is right!\n"
	.string "Come on!$"

DewfordTown_Gym_Text_TakaoDefeat:
	.string "Not enough power…$"

DewfordTown_Gym_Text_TakaoPostBattle:
	.string "Your skill overcame my strength!\n"
	.string "Your technique is commendable!$"

DewfordTown_Gym_Text_JocelynIntro:
	.string "There's no need for BRAWLY to be\n"
	.string "involved!\p"
	.string "I'll crush you!$"

DewfordTown_Gym_Text_JocelynDefeat:
	.string "But… How?\n"
	.string "How could I lose so easily?$"

DewfordTown_Gym_Text_JocelynPostBattle:
	.string "I'm not going to waste this loss.\n"
	.string "I'll use it to motivate me to train!\p"
	.string "One day I'll become a GYM LEADER…\p"
	.string "No, I'll become the POKéMON LEAGUE\n"
	.string "CHAMPION!$"

DewfordTown_Gym_Text_LauraIntro:
	.string "Don't you dare brush me off!\n"
	.string "It's not my fault if you cry!$"

DewfordTown_Gym_Text_LauraDefeat:
	.string "Waaaaaaah!\n"
	.string "I lost!$"

DewfordTown_Gym_Text_LauraPostBattle:
	.string "I battle in the dark to make my heart\n"
	.string "stronger.\p"
	.string "But because it's so dark, I can never\n"
	.string "see BRAWLY's face…$"

DewfordTown_Gym_Text_LilithIntro:
	.string "Ufufu…\n"
	.string "Are you stumbling around in the dark?$"

DewfordTown_Gym_Text_LilithDefeat:
	.string "Oh, you…\n"
	.string "I don't want to know you!$"

DewfordTown_Gym_Text_LilithPostBattle:
	.string "You deserve to stay lost and end up\n"
	.string "back at the entrance again!$"

DewfordTown_Gym_Text_BrendenIntro:
	.string "I'll show you the gumption of\n"
	.string "a sailing man!$"

DewfordTown_Gym_Text_BrendenDefeat:
	.string "How'd this happen?\n"
	.string "It's not like me to lose this way!$"

DewfordTown_Gym_Text_BrendenPostBattle:
	.string "Oh, aye! You're worthy of seeing\n"
	.string "our GYM LEADER.$"

DewfordTown_Gym_Text_CristianIntro:
	.string "If you mean to pass, it has to be\n"
	.string "through me!$"

DewfordTown_Gym_Text_CristianDefeat:
	.string "Grrrrr!\n"
	.string "Vastly overpowered!$"

DewfordTown_Gym_Text_CristianPostBattle:
	.string "You win!\n"
	.string "Go after that BADGE!$"

DewfordTown_Gym_Text_BrawlyIntro:
	.string "I'm BRAWLY!\n"
	.string "DEWFORD's GYM LEADER!\p"
	.string "I've been churned in the rough waves\n"
	.string "of these parts, and I've grown tough\l"
	.string "in the pitch-black cave!\p"
	.string "So you wanted to challenge me?\n"
	.string "Let me see what you're made of!$"

DewfordTown_Gym_Text_BrawlyDefeat:
	.string "Whoah, wow! You made a much bigger\n"
	.string "splash than I expected!\p"
	.string "You swamped me!\p"
	.string "Okay, you've got me.\n"
	.string "Take this GYM BADGE!$"

DewfordTown_Gym_Text_ReceivedKnuckleBadge:
	.string "{PLAYER} received the KNUCKLE BADGE\n"
	.string "from BRAWLY.$"

DewfordTown_Gym_Text_KnuckleBadgeInfoTakeThis:
	.string "The KNUCKLE BADGE makes all POKéMON\n"
	.string "up to Level 30, even those you get in\l"
	.string "trades, obey without question.\p"
	.string "And, you'll be able to use the HM move\n"
	.string "FLASH outside of battle.\p"
	.string "If you'd like, use this TECHNICAL\n"
	.string "MACHINE, too.$"

DewfordTown_Gym_Text_ExplainBulkUp:
	.string "That TM08 contains BULK UP.\p"
	.string "It's a move that raises both ATTACK\n"
	.string "and DEFENSE stats.\p"
	.string "… … … … … …$"

DewfordTown_Gym_Text_RegisteredBrawly:
	.string "Registered GYM LEADER BRAWLY\n"
	.string "in the POKéNAV.$"

DewfordTown_Gym_Text_BrawlyPostBattle:
	.string "I can see your talent becoming a giant\n"
	.string "wave to cause a storm of astonishment\l"
	.string "among TRAINERS one day!$"

DewfordTown_Gym_Text_GymStatue:
	.string "DEWFORD TOWN POKéMON GYM$"

DewfordTown_Gym_Text_GymStatueCertified:
	.string "DEWFORD TOWN POKéMON GYM\p"
	.string "BRAWLY'S CERTIFIED TRAINERS:\n"
	.string "{PLAYER}$"

DewfordTown_Gym_Text_BrawlyPreRematch:
	.string "BRAWLY: A wave may draw back, but it\n"
	.string "always returns to the shore.\p"
	.string "A giant wave of a talent like you…\n"
	.string "I knew you would return!\p"
	.string "Show me how much higher\n"
	.string "you've gone!$"

DewfordTown_Gym_Text_BrawlyRematchDefeat:
	.string "Wow!\n"
	.string "Swamped again!$"

DewfordTown_Gym_Text_BrawlyPostRematch:
	.string "BRAWLY: Battling is vast and it's deep.\n"
	.string "You can't see the bottom.\l"
	.string "It's just like the sea of HOENN!$"

DewfordTown_Gym_Text_BrawlyRematchNeedTwoMons:
	.string "BRAWLY: A wave may draw back, but it\n"
	.string "always returns to the shore.\p"
	.string "A giant wave of a talent like you…\n"
	.string "I knew you would return!\p"
	.string "Oh? You only have one POKéMON\n"
	.string "that can battle.\p"
	.string "I'm sorry, but I'd like you to come back\n"
>>>>>>> upstream/master
	.string "with at least two POKéMON.$"
