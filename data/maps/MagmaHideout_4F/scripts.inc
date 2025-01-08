<<<<<<< HEAD
# 1 "data/maps/MagmaHideout_4F/scripts.pory"

# 2 "data/maps/MagmaHideout_4F/scripts.pory"
.set LOCALID_GROUDON, 1
# 3 "data/maps/MagmaHideout_4F/scripts.pory"
.set LOCALID_GRUNT_1, 2
# 4 "data/maps/MagmaHideout_4F/scripts.pory"
.set LOCALID_GRUNT_2, 3
# 5 "data/maps/MagmaHideout_4F/scripts.pory"
.set LOCALID_GRUNT_3, 4
# 6 "data/maps/MagmaHideout_4F/scripts.pory"
.set LOCALID_TABITHA, 5
# 7 "data/maps/MagmaHideout_4F/scripts.pory"
.set LOCALID_MAXIE, 6
# 8 "data/maps/MagmaHideout_4F/scripts.pory"
.set LOCALID_GROUDON_SLEEPING, 7
# 9 "data/maps/MagmaHideout_4F/scripts.pory"

# 10 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_MapScripts::
# 11 "data/maps/MagmaHideout_4F/scripts.pory"
	.byte 0
# 12 "data/maps/MagmaHideout_4F/scripts.pory"

# 13 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_EventScript_Maxie::
# 14 "data/maps/MagmaHideout_4F/scripts.pory"
	lockall
# 15 "data/maps/MagmaHideout_4F/scripts.pory"
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
# 16 "data/maps/MagmaHideout_4F/scripts.pory"
	msgbox MagmaHideout_4F_Text_MaxieAwakenGroudon, MSGBOX_DEFAULT
# 17 "data/maps/MagmaHideout_4F/scripts.pory"
	closemessage
# 18 "data/maps/MagmaHideout_4F/scripts.pory"
	delay 20
# 19 "data/maps/MagmaHideout_4F/scripts.pory"
	setvar VAR_RESULT, 1
# 20 "data/maps/MagmaHideout_4F/scripts.pory"
	playse SE_M_DETECT
# 21 "data/maps/MagmaHideout_4F/scripts.pory"
	dofieldeffectsparkle 18, 42, 0
# 22 "data/maps/MagmaHideout_4F/scripts.pory"
	waitfieldeffect FLDEFF_SPARKLE
# 23 "data/maps/MagmaHideout_4F/scripts.pory"
	setvar VAR_RESULT, 1
# 24 "data/maps/MagmaHideout_4F/scripts.pory"
	playfanfare MUS_AWAKEN_LEGEND
# 25 "data/maps/MagmaHideout_4F/scripts.pory"
	playse SE_ORB
# 26 "data/maps/MagmaHideout_4F/scripts.pory"
	special DoOrbEffect
# 27 "data/maps/MagmaHideout_4F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
# 28 "data/maps/MagmaHideout_4F/scripts.pory"
	waitmovement 0
# 29 "data/maps/MagmaHideout_4F/scripts.pory"
	delay 150
# 30 "data/maps/MagmaHideout_4F/scripts.pory"
	removeobject LOCALID_GROUDON_SLEEPING
# 31 "data/maps/MagmaHideout_4F/scripts.pory"
	addobject LOCALID_GROUDON
# 32 "data/maps/MagmaHideout_4F/scripts.pory"
	waitstate
# 33 "data/maps/MagmaHideout_4F/scripts.pory"
	delay 60
# 34 "data/maps/MagmaHideout_4F/scripts.pory"
	applymovement LOCALID_GROUDON, MagmaHideout_4F_Movement_GroudonApproach
# 35 "data/maps/MagmaHideout_4F/scripts.pory"
	waitmovement 0
# 36 "data/maps/MagmaHideout_4F/scripts.pory"
	special FadeOutOrbEffect
# 37 "data/maps/MagmaHideout_4F/scripts.pory"
	waitstate
# 38 "data/maps/MagmaHideout_4F/scripts.pory"
	setvar VAR_0x8004, 1  @ vertical pan
# 39 "data/maps/MagmaHideout_4F/scripts.pory"
	setvar VAR_0x8005, 1  @ horizontal pan
# 40 "data/maps/MagmaHideout_4F/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 41 "data/maps/MagmaHideout_4F/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 42 "data/maps/MagmaHideout_4F/scripts.pory"
	special ShakeCamera
# 43 "data/maps/MagmaHideout_4F/scripts.pory"
	waitstate
# 44 "data/maps/MagmaHideout_4F/scripts.pory"
	applymovement LOCALID_GROUDON, MagmaHideout_4F_Movement_GroudonExit
# 45 "data/maps/MagmaHideout_4F/scripts.pory"
	waitmovement 0
# 46 "data/maps/MagmaHideout_4F/scripts.pory"
	removeobject LOCALID_GROUDON
# 47 "data/maps/MagmaHideout_4F/scripts.pory"
	delay 4
# 48 "data/maps/MagmaHideout_4F/scripts.pory"
	setvar VAR_0x8004, 2  @ vertical pan
# 49 "data/maps/MagmaHideout_4F/scripts.pory"
	setvar VAR_0x8005, 2  @ horizontal pan
# 50 "data/maps/MagmaHideout_4F/scripts.pory"
	setvar VAR_0x8006, 8  @ num shakes
# 51 "data/maps/MagmaHideout_4F/scripts.pory"
	setvar VAR_0x8007, 5  @ shake delay
# 52 "data/maps/MagmaHideout_4F/scripts.pory"
	special ShakeCamera
# 53 "data/maps/MagmaHideout_4F/scripts.pory"
	waitstate
# 54 "data/maps/MagmaHideout_4F/scripts.pory"
	delay 30
# 55 "data/maps/MagmaHideout_4F/scripts.pory"
	applymovement LOCALID_MAXIE, MagmaHideout_4F_Movement_MaxieLookAround
# 56 "data/maps/MagmaHideout_4F/scripts.pory"
	waitmovement 0
# 57 "data/maps/MagmaHideout_4F/scripts.pory"
	msgbox MagmaHideout_4F_Text_MaxieGroudonWhatsWrong, MSGBOX_DEFAULT
# 58 "data/maps/MagmaHideout_4F/scripts.pory"
	closemessage
# 59 "data/maps/MagmaHideout_4F/scripts.pory"
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
# 60 "data/maps/MagmaHideout_4F/scripts.pory"
	waitmovement 0
# 61 "data/maps/MagmaHideout_4F/scripts.pory"
	delay 30
# 62 "data/maps/MagmaHideout_4F/scripts.pory"
	applymovement LOCALID_MAXIE, Common_Movement_FacePlayer
# 63 "data/maps/MagmaHideout_4F/scripts.pory"
	waitmovement 0
# 64 "data/maps/MagmaHideout_4F/scripts.pory"
	msgbox MagmaHideout_4F_Text_MaxieOhItWasYou, MSGBOX_DEFAULT
# 65 "data/maps/MagmaHideout_4F/scripts.pory"
	closemessage
# 66 "data/maps/MagmaHideout_4F/scripts.pory"
	trainerbattle_no_intro TRAINER_MAXIE_MAGMA_HIDEOUT, MagmaHideout_4F_Text_MaxieDefeat
# 67 "data/maps/MagmaHideout_4F/scripts.pory"
	msgbox MagmaHideout_4F_Text_MaxieImGoingAfterGroudon, MSGBOX_DEFAULT
# 68 "data/maps/MagmaHideout_4F/scripts.pory"
	closemessage
# 69 "data/maps/MagmaHideout_4F/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_CAPTAIN_STERN
# 70 "data/maps/MagmaHideout_4F/scripts.pory"
	clearflag FLAG_HIDE_SLATEPORT_CITY_GABBY_AND_TY
# 71 "data/maps/MagmaHideout_4F/scripts.pory"
	setvar VAR_SLATEPORT_CITY_STATE, 1
# 72 "data/maps/MagmaHideout_4F/scripts.pory"
	setflag FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT
# 73 "data/maps/MagmaHideout_4F/scripts.pory"
	setvar VAR_SLATEPORT_HARBOR_STATE, 1
# 74 "data/maps/MagmaHideout_4F/scripts.pory"
	fadescreen FADE_TO_BLACK
# 75 "data/maps/MagmaHideout_4F/scripts.pory"
	removeobject LOCALID_MAXIE
# 76 "data/maps/MagmaHideout_4F/scripts.pory"
	removeobject LOCALID_GRUNT_1
# 77 "data/maps/MagmaHideout_4F/scripts.pory"
	removeobject LOCALID_GRUNT_2
# 78 "data/maps/MagmaHideout_4F/scripts.pory"
	removeobject LOCALID_GRUNT_3
# 79 "data/maps/MagmaHideout_4F/scripts.pory"
	removeobject LOCALID_TABITHA
# 80 "data/maps/MagmaHideout_4F/scripts.pory"
	setflag FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS
# 81 "data/maps/MagmaHideout_4F/scripts.pory"
	fadescreen FADE_FROM_BLACK
# 82 "data/maps/MagmaHideout_4F/scripts.pory"
	releaseall
# 83 "data/maps/MagmaHideout_4F/scripts.pory"
	end
# 84 "data/maps/MagmaHideout_4F/scripts.pory"

# 85 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Movement_GroudonApproach:
# 86 "data/maps/MagmaHideout_4F/scripts.pory"
	delay_16
# 87 "data/maps/MagmaHideout_4F/scripts.pory"
	delay_16
# 88 "data/maps/MagmaHideout_4F/scripts.pory"
	walk_slow_down
# 89 "data/maps/MagmaHideout_4F/scripts.pory"
	delay_16
# 90 "data/maps/MagmaHideout_4F/scripts.pory"
	delay_16
# 91 "data/maps/MagmaHideout_4F/scripts.pory"
	delay_16
# 92 "data/maps/MagmaHideout_4F/scripts.pory"
	walk_slow_down
# 93 "data/maps/MagmaHideout_4F/scripts.pory"
	delay_16
# 94 "data/maps/MagmaHideout_4F/scripts.pory"
	delay_16
# 95 "data/maps/MagmaHideout_4F/scripts.pory"
	delay_16
# 96 "data/maps/MagmaHideout_4F/scripts.pory"
	step_end
# 97 "data/maps/MagmaHideout_4F/scripts.pory"

# 98 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Movement_GroudonExit:
# 99 "data/maps/MagmaHideout_4F/scripts.pory"
	slide_up
# 100 "data/maps/MagmaHideout_4F/scripts.pory"
	slide_up
# 101 "data/maps/MagmaHideout_4F/scripts.pory"
	step_end
# 102 "data/maps/MagmaHideout_4F/scripts.pory"

# 103 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Movement_MaxieLookAround:
# 104 "data/maps/MagmaHideout_4F/scripts.pory"
	face_left
# 105 "data/maps/MagmaHideout_4F/scripts.pory"
	delay_16
# 106 "data/maps/MagmaHideout_4F/scripts.pory"
	face_right
# 107 "data/maps/MagmaHideout_4F/scripts.pory"
	delay_16
# 108 "data/maps/MagmaHideout_4F/scripts.pory"
	face_left
# 109 "data/maps/MagmaHideout_4F/scripts.pory"
	delay_16
# 110 "data/maps/MagmaHideout_4F/scripts.pory"
	face_right
# 111 "data/maps/MagmaHideout_4F/scripts.pory"
	delay_16
# 112 "data/maps/MagmaHideout_4F/scripts.pory"
	face_up
# 113 "data/maps/MagmaHideout_4F/scripts.pory"
	delay_16
# 114 "data/maps/MagmaHideout_4F/scripts.pory"
	delay_16
# 115 "data/maps/MagmaHideout_4F/scripts.pory"
	step_end
# 116 "data/maps/MagmaHideout_4F/scripts.pory"

# 117 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_EventScript_Grunt11::
# 118 "data/maps/MagmaHideout_4F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_11, MagmaHideout_4F_Text_Grunt11Intro, MagmaHideout_4F_Text_Grunt11Defeat
# 119 "data/maps/MagmaHideout_4F/scripts.pory"
	msgbox MagmaHideout_4F_Text_Grunt11PostBattle, MSGBOX_AUTOCLOSE
# 120 "data/maps/MagmaHideout_4F/scripts.pory"
	end
# 121 "data/maps/MagmaHideout_4F/scripts.pory"

# 122 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_EventScript_Grunt12::
# 123 "data/maps/MagmaHideout_4F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_12, MagmaHideout_4F_Text_Grunt12Intro, MagmaHideout_4F_Text_Grunt12Defeat
# 124 "data/maps/MagmaHideout_4F/scripts.pory"
	msgbox MagmaHideout_4F_Text_Grunt12PostBattle, MSGBOX_AUTOCLOSE
# 125 "data/maps/MagmaHideout_4F/scripts.pory"
	end
# 126 "data/maps/MagmaHideout_4F/scripts.pory"

# 127 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_EventScript_Grunt13::
# 128 "data/maps/MagmaHideout_4F/scripts.pory"
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_13, MagmaHideout_4F_Text_Grunt13Intro, MagmaHideout_4F_Text_Grunt13Defeat
# 129 "data/maps/MagmaHideout_4F/scripts.pory"
	msgbox MagmaHideout_4F_Text_Grunt13PostBattle, MSGBOX_AUTOCLOSE
# 130 "data/maps/MagmaHideout_4F/scripts.pory"
	end
# 131 "data/maps/MagmaHideout_4F/scripts.pory"

# 132 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_EventScript_Tabitha::
# 133 "data/maps/MagmaHideout_4F/scripts.pory"
	trainerbattle_single TRAINER_TABITHA_MAGMA_HIDEOUT, MagmaHideout_4F_Text_TabithaIntro, MagmaHideout_4F_Text_TabithaDefeat
# 134 "data/maps/MagmaHideout_4F/scripts.pory"
	msgbox MagmaHideout_4F_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
# 135 "data/maps/MagmaHideout_4F/scripts.pory"
	end
# 136 "data/maps/MagmaHideout_4F/scripts.pory"

# 137 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_Grunt11Intro:
# 138 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "I want to see GROUDON, too, but they\n"
# 139 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "won't let me see even its tail…\p"
# 140 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "It's got me feeling really frustrated.\p"
# 141 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Oh, no!\n"
# 142 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "I blabbed about GROUDON!$"
# 143 "data/maps/MagmaHideout_4F/scripts.pory"

# 144 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_Grunt11Defeat:
# 145 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "I guess it's impossible to win if one\n"
# 146 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "doesn't have a calm mind…$"
# 147 "data/maps/MagmaHideout_4F/scripts.pory"

# 148 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_Grunt11PostBattle:
# 149 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "I wonder if GROUDON even has a tail?$"
# 150 "data/maps/MagmaHideout_4F/scripts.pory"

# 151 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_Grunt12Intro:
# 152 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Fuhahaha!\n"
# 153 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Soon! Very soon!\l"
# 154 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Our grand objective will be achieved!$"
# 155 "data/maps/MagmaHideout_4F/scripts.pory"

# 156 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_Grunt12Defeat:
# 157 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Grrr…\n"
# 158 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "I've come so far, but now this?$"
# 159 "data/maps/MagmaHideout_4F/scripts.pory"

# 160 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_Grunt12PostBattle:
# 161 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "MAXIE, sir!\n"
# 162 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "An intruder is headed your way!$"
# 163 "data/maps/MagmaHideout_4F/scripts.pory"

# 164 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_Grunt13Intro:
# 165 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "You're not finished yet!\n"
# 166 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "You're not getting by me easily!$"
# 167 "data/maps/MagmaHideout_4F/scripts.pory"

# 168 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_Grunt13Defeat:
# 169 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Was I that easy to knock down?$"
# 170 "data/maps/MagmaHideout_4F/scripts.pory"

# 171 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_Grunt13PostBattle:
# 172 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "C-come on, one more match…$"
# 173 "data/maps/MagmaHideout_4F/scripts.pory"

# 174 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_TabithaIntro:
# 175 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Hehehe!\n"
# 176 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "You made it this far, so I'll tell you!\p"
# 177 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "That's right!\n"
# 178 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Up ahead, GROUDON is sleeping!\p"
# 179 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "MAXIE went to GROUDON just seconds\n"
# 180 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "ago!\p"
# 181 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "It's going to awaken real soon!\n"
# 182 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Hehe! Hehehe!$"
# 183 "data/maps/MagmaHideout_4F/scripts.pory"

# 184 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_TabithaDefeat:
# 185 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Taken down again…\n"
# 186 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Hehe…$"
# 187 "data/maps/MagmaHideout_4F/scripts.pory"

# 188 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_TabithaPostBattle:
# 189 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "…And while you wasted time with me,\n"
# 190 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "MAXIE should have awakened GROUDON…$"
# 191 "data/maps/MagmaHideout_4F/scripts.pory"

# 192 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_MaxieAwakenGroudon:
# 193 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "MAXIE: GROUDON…\p"
# 194 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Nothing could awaken you from your\n"
# 195 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "sleep bathed in magma…\p"
# 196 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "This BLUE ORB is what you sought.\n"
# 197 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Wasn't it?\p"
# 198 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "I have brought you the BLUE ORB.\n"
# 199 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Let its shine awaken you!\p"
# 200 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "And show me…\n"
# 201 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Show me the full extent of your power!$"
# 202 "data/maps/MagmaHideout_4F/scripts.pory"

# 203 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_MaxieGroudonWhatsWrong:
# 204 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "MAXIE: GROUDON!\n"
# 205 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "What's wrong?\p"
# 206 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Wasn't the BLUE ORB the key?\p"
# 207 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "GROUDON!\n"
# 208 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Where have you gone…$"
# 209 "data/maps/MagmaHideout_4F/scripts.pory"

# 210 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_MaxieOhItWasYou:
# 211 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "MAXIE: Oh, so it was you?\p"
# 212 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "I've seen you poking around uninvited\n"
# 213 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "here and there…\p"
# 214 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "I get it now!\n"
# 215 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "You must have pulled a cheap stunt!$"
# 216 "data/maps/MagmaHideout_4F/scripts.pory"

# 217 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_MaxieDefeat:
# 218 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "What makes you so adept at handling\n"
# 219 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "POKéMON?$"
# 220 "data/maps/MagmaHideout_4F/scripts.pory"

# 221 "data/maps/MagmaHideout_4F/scripts.pory"
MagmaHideout_4F_Text_MaxieImGoingAfterGroudon:
# 222 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "MAXIE: There has to be some reason\n"
# 223 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "why GROUDON fled…\p"
# 224 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "That's what you're trying to say,\n"
# 225 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "aren't you?\p"
# 226 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "… … … … … …\n"
# 227 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "… … … … … …\p"
# 228 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "Humph…\n"
# 229 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "You think I didn't know that?\p"
# 230 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "With GROUDON gone, there is no longer\n"
# 231 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "any need for this blasted volcano.\p"
# 232 "data/maps/MagmaHideout_4F/scripts.pory"
	.string "I am going after GROUDON, so this\n"
# 233 "data/maps/MagmaHideout_4F/scripts.pory"
=======
.set LOCALID_GROUDON, 1
.set LOCALID_GRUNT_1, 2
.set LOCALID_GRUNT_2, 3
.set LOCALID_GRUNT_3, 4
.set LOCALID_TABITHA, 5
.set LOCALID_MAXIE, 6
.set LOCALID_GROUDON_SLEEPING, 7

MagmaHideout_4F_MapScripts::
	.byte 0

MagmaHideout_4F_EventScript_Maxie::
	lockall
	playbgm MUS_ENCOUNTER_MAGMA, FALSE
	msgbox MagmaHideout_4F_Text_MaxieAwakenGroudon, MSGBOX_DEFAULT
	closemessage
	delay 20
	setvar VAR_RESULT, 1
	playse SE_M_DETECT
	dofieldeffectsparkle 18, 42, 0
	waitfieldeffect FLDEFF_SPARKLE
	setvar VAR_RESULT, 1
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	delay 150
	removeobject LOCALID_GROUDON_SLEEPING
	addobject LOCALID_GROUDON
	waitstate
	delay 60
	applymovement LOCALID_GROUDON, MagmaHideout_4F_Movement_GroudonApproach
	waitmovement 0
	special FadeOutOrbEffect
	waitstate
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 1  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	applymovement LOCALID_GROUDON, MagmaHideout_4F_Movement_GroudonExit
	waitmovement 0
	removeobject LOCALID_GROUDON
	delay 4
	setvar VAR_0x8004, 2  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	applymovement LOCALID_MAXIE, MagmaHideout_4F_Movement_MaxieLookAround
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieGroudonWhatsWrong, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceFasterRight
	waitmovement 0
	delay 30
	applymovement LOCALID_MAXIE, Common_Movement_FacePlayer
	waitmovement 0
	msgbox MagmaHideout_4F_Text_MaxieOhItWasYou, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_MAXIE_MAGMA_HIDEOUT, MagmaHideout_4F_Text_MaxieDefeat
	msgbox MagmaHideout_4F_Text_MaxieImGoingAfterGroudon, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_SLATEPORT_CITY_CAPTAIN_STERN
	clearflag FLAG_HIDE_SLATEPORT_CITY_GABBY_AND_TY
	setvar VAR_SLATEPORT_CITY_STATE, 1
	setflag FLAG_GROUDON_AWAKENED_MAGMA_HIDEOUT
	setvar VAR_SLATEPORT_HARBOR_STATE, 1
	fadescreen FADE_TO_BLACK
	removeobject LOCALID_MAXIE
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	removeobject LOCALID_GRUNT_3
	removeobject LOCALID_TABITHA
	setflag FLAG_HIDE_MAGMA_HIDEOUT_GRUNTS
	fadescreen FADE_FROM_BLACK
	releaseall
	end

MagmaHideout_4F_Movement_GroudonApproach:
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	walk_slow_down
	delay_16
	delay_16
	delay_16
	step_end

MagmaHideout_4F_Movement_GroudonExit:
	slide_up
	slide_up
	step_end

MagmaHideout_4F_Movement_MaxieLookAround:
	face_left
	delay_16
	face_right
	delay_16
	face_left
	delay_16
	face_right
	delay_16
	face_up
	delay_16
	delay_16
	step_end

MagmaHideout_4F_EventScript_Grunt11::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_11, MagmaHideout_4F_Text_Grunt11Intro, MagmaHideout_4F_Text_Grunt11Defeat
	msgbox MagmaHideout_4F_Text_Grunt11PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt12::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_12, MagmaHideout_4F_Text_Grunt12Intro, MagmaHideout_4F_Text_Grunt12Defeat
	msgbox MagmaHideout_4F_Text_Grunt12PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Grunt13::
	trainerbattle_single TRAINER_GRUNT_MAGMA_HIDEOUT_13, MagmaHideout_4F_Text_Grunt13Intro, MagmaHideout_4F_Text_Grunt13Defeat
	msgbox MagmaHideout_4F_Text_Grunt13PostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_EventScript_Tabitha::
	trainerbattle_single TRAINER_TABITHA_MAGMA_HIDEOUT, MagmaHideout_4F_Text_TabithaIntro, MagmaHideout_4F_Text_TabithaDefeat
	msgbox MagmaHideout_4F_Text_TabithaPostBattle, MSGBOX_AUTOCLOSE
	end

MagmaHideout_4F_Text_Grunt11Intro:
	.string "I want to see GROUDON, too, but they\n"
	.string "won't let me see even its tail…\p"
	.string "It's got me feeling really frustrated.\p"
	.string "Oh, no!\n"
	.string "I blabbed about GROUDON!$"

MagmaHideout_4F_Text_Grunt11Defeat:
	.string "I guess it's impossible to win if one\n"
	.string "doesn't have a calm mind…$"

MagmaHideout_4F_Text_Grunt11PostBattle:
	.string "I wonder if GROUDON even has a tail?$"

MagmaHideout_4F_Text_Grunt12Intro:
	.string "Fuhahaha!\n"
	.string "Soon! Very soon!\l"
	.string "Our grand objective will be achieved!$"

MagmaHideout_4F_Text_Grunt12Defeat:
	.string "Grrr…\n"
	.string "I've come so far, but now this?$"

MagmaHideout_4F_Text_Grunt12PostBattle:
	.string "MAXIE, sir!\n"
	.string "An intruder is headed your way!$"

MagmaHideout_4F_Text_Grunt13Intro:
	.string "You're not finished yet!\n"
	.string "You're not getting by me easily!$"

MagmaHideout_4F_Text_Grunt13Defeat:
	.string "Was I that easy to knock down?$"

MagmaHideout_4F_Text_Grunt13PostBattle:
	.string "C-come on, one more match…$"

MagmaHideout_4F_Text_TabithaIntro:
	.string "Hehehe!\n"
	.string "You made it this far, so I'll tell you!\p"
	.string "That's right!\n"
	.string "Up ahead, GROUDON is sleeping!\p"
	.string "MAXIE went to GROUDON just seconds\n"
	.string "ago!\p"
	.string "It's going to awaken real soon!\n"
	.string "Hehe! Hehehe!$"

MagmaHideout_4F_Text_TabithaDefeat:
	.string "Taken down again…\n"
	.string "Hehe…$"

MagmaHideout_4F_Text_TabithaPostBattle:
	.string "…And while you wasted time with me,\n"
	.string "MAXIE should have awakened GROUDON…$"

MagmaHideout_4F_Text_MaxieAwakenGroudon:
	.string "MAXIE: GROUDON…\p"
	.string "Nothing could awaken you from your\n"
	.string "sleep bathed in magma…\p"
	.string "This BLUE ORB is what you sought.\n"
	.string "Wasn't it?\p"
	.string "I have brought you the BLUE ORB.\n"
	.string "Let its shine awaken you!\p"
	.string "And show me…\n"
	.string "Show me the full extent of your power!$"

MagmaHideout_4F_Text_MaxieGroudonWhatsWrong:
	.string "MAXIE: GROUDON!\n"
	.string "What's wrong?\p"
	.string "Wasn't the BLUE ORB the key?\p"
	.string "GROUDON!\n"
	.string "Where have you gone…$"

MagmaHideout_4F_Text_MaxieOhItWasYou:
	.string "MAXIE: Oh, so it was you?\p"
	.string "I've seen you poking around uninvited\n"
	.string "here and there…\p"
	.string "I get it now!\n"
	.string "You must have pulled a cheap stunt!$"

MagmaHideout_4F_Text_MaxieDefeat:
	.string "What makes you so adept at handling\n"
	.string "POKéMON?$"

MagmaHideout_4F_Text_MaxieImGoingAfterGroudon:
	.string "MAXIE: There has to be some reason\n"
	.string "why GROUDON fled…\p"
	.string "That's what you're trying to say,\n"
	.string "aren't you?\p"
	.string "… … … … … …\n"
	.string "… … … … … …\p"
	.string "Humph…\n"
	.string "You think I didn't know that?\p"
	.string "With GROUDON gone, there is no longer\n"
	.string "any need for this blasted volcano.\p"
	.string "I am going after GROUDON, so this\n"
>>>>>>> upstream/master
	.string "is where we part!$"
