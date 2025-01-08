<<<<<<< HEAD
import re

def battle_frontier_mons(data):
    data = re.sub(re.escape(".itemTableId = BATTLE_FRONTIER_"), ".heldItem = ", data)
    data = re.sub(re.escape("FacilityMon"), "TrainerMon", data)
    data = re.sub(re.escape(".evSpread = 0,"), ".ev = NULL,", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(252, 0, 0, 0, 0, 0),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,"), ".ev = TRAINER_PARTY_EVS(0, 170, 170, 170, 0, 0),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_ATTACK,"), ".ev = TRAINER_PARTY_EVS(0, 252, 0, 0, 0, 0),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SPEED,"), ".ev = TRAINER_PARTY_EVS(0, 0, 0, 252, 0, 0),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(170, 170, 170, 0, 0, 0),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,"), ".ev = TRAINER_PARTY_EVS(0, 170, 170, 0, 170, 0),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(170, 0, 0, 170, 170, 0),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(170, 0, 0, 170, 170, 0),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(170, 0, 170, 0, 170, 0),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_DEFENSE,"), ".ev = TRAINER_PARTY_EVS(0, 0, 170, 170, 170, 0),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,"), ".ev = TRAINER_PARTY_EVS(0, 170, 0, 170, 170, 0),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(170, 170, 0, 0, 170, 0),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(252, 0, 0, 0, 252, 0),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,"), ".ev = TRAINER_PARTY_EVS(0, 252, 0, 0, 252, 0),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,"), ".ev = TRAINER_PARTY_EVS(0, 0, 252, 0, 252, 0),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,"), ".ev = TRAINER_PARTY_EVS(0, 0, 0, 252, 252, 0),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SPEED | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(102, 102, 102, 102, 0, 102),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,"), ".ev = TRAINER_PARTY_EVS(0, 128, 128, 0, 128, 128),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,"), ".ev = TRAINER_PARTY_EVS(0, 0, 170, 0, 170, 170),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(84, 84, 84, 84, 84, 84),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SPEED | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,"), ".ev = TRAINER_PARTY_EVS(0, 128, 128, 128, 0, 128),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,"), ".ev = TRAINER_PARTY_EVS(0, 170, 170, 0, 0, 170),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(102, 0, 102, 102, 102, 102),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,"), ".ev = TRAINER_PARTY_EVS(0, 170, 0, 0, 170, 170),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(128, 0, 128, 0, 128, 128),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(128, 128, 128, 0, 0, 128),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(170, 0, 0, 170, 0, 170),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,"), ".ev = TRAINER_PARTY_EVS(0, 170, 0, 170, 0, 170),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(252, 0, 0, 0, 0, 252),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SPEED | F_EV_SPREAD_DEFENSE,"), ".ev = TRAINER_PARTY_EVS(0, 0, 170, 170, 0, 170),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SPEED | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(128, 0, 128, 128, 0, 128),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(170, 0, 0, 0, 170, 170),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(170, 0, 170, 0, 0, 170),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(170, 170, 0, 0, 0, 170),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,"), ".ev = TRAINER_PARTY_EVS(0, 252, 0, 0, 0, 252),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK,"), ".ev = TRAINER_PARTY_EVS(0, 0, 0, 0, 252, 252),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,"), ".ev = TRAINER_PARTY_EVS(0, 0, 252, 0, 0, 252),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(252, 252, 0, 0, 0, 0),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(252, 0, 0, 252, 0, 0),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(170, 0, 170, 170, 0, 0),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(170, 170, 0, 170, 0, 0),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,"), ".ev = TRAINER_PARTY_EVS(0, 252, 0, 252, 0, 0),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(252, 0, 252, 0, 0, 0),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,"), ".ev = TRAINER_PARTY_EVS(0, 252, 252, 0, 0, 0),", data)

    return data

with open('src/data/battle_frontier/battle_frontier_mons.h', 'r') as file:
    data = file.read()
with open('src/data/battle_frontier/battle_frontier_mons.h', 'w') as file:
    file.write(battle_frontier_mons(data))

with open('src/data/battle_frontier/battle_tent.h', 'r') as file:
    data = file.read()
with open('src/data/battle_frontier/battle_tent.h', 'w') as file:
    file.write(battle_frontier_mons(data))
=======
import re

def battle_frontier_mons(data):
    data = re.sub(re.escape(".itemTableId = BATTLE_FRONTIER_"), ".heldItem = ", data)
    data = re.sub(re.escape("FacilityMon"), "TrainerMon", data)
    data = re.sub(re.escape(".evSpread = 0,"), ".ev = NULL,", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(252, 0, 0, 0, 0, 0),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,"), ".ev = TRAINER_PARTY_EVS(0, 170, 170, 170, 0, 0),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_ATTACK,"), ".ev = TRAINER_PARTY_EVS(0, 252, 0, 0, 0, 0),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SPEED,"), ".ev = TRAINER_PARTY_EVS(0, 0, 0, 252, 0, 0),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(170, 170, 170, 0, 0, 0),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,"), ".ev = TRAINER_PARTY_EVS(0, 170, 170, 0, 170, 0),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(170, 0, 0, 170, 170, 0),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(170, 0, 0, 170, 170, 0),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(170, 0, 170, 0, 170, 0),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_DEFENSE,"), ".ev = TRAINER_PARTY_EVS(0, 0, 170, 170, 170, 0),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,"), ".ev = TRAINER_PARTY_EVS(0, 170, 0, 170, 170, 0),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(170, 170, 0, 0, 170, 0),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(252, 0, 0, 0, 252, 0),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,"), ".ev = TRAINER_PARTY_EVS(0, 252, 0, 0, 252, 0),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,"), ".ev = TRAINER_PARTY_EVS(0, 0, 252, 0, 252, 0),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED,"), ".ev = TRAINER_PARTY_EVS(0, 0, 0, 252, 252, 0),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SPEED | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(102, 102, 102, 102, 0, 102),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,"), ".ev = TRAINER_PARTY_EVS(0, 128, 128, 0, 128, 128),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE,"), ".ev = TRAINER_PARTY_EVS(0, 0, 170, 0, 170, 170),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(84, 84, 84, 84, 84, 84),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SPEED | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,"), ".ev = TRAINER_PARTY_EVS(0, 128, 128, 128, 0, 128),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,"), ".ev = TRAINER_PARTY_EVS(0, 170, 170, 0, 0, 170),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_SPEED | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(102, 0, 102, 102, 102, 102),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_ATTACK,"), ".ev = TRAINER_PARTY_EVS(0, 170, 0, 0, 170, 170),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(128, 0, 128, 0, 128, 128),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(128, 128, 128, 0, 0, 128),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(170, 0, 0, 170, 0, 170),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,"), ".ev = TRAINER_PARTY_EVS(0, 170, 0, 170, 0, 170),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(252, 0, 0, 0, 0, 252),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SPEED | F_EV_SPREAD_DEFENSE,"), ".ev = TRAINER_PARTY_EVS(0, 0, 170, 170, 0, 170),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SPEED | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(128, 0, 128, 128, 0, 128),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK | F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(170, 0, 0, 0, 170, 170),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(170, 0, 170, 0, 0, 170),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(170, 170, 0, 0, 0, 170),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_ATTACK,"), ".ev = TRAINER_PARTY_EVS(0, 252, 0, 0, 0, 252),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_SP_ATTACK,"), ".ev = TRAINER_PARTY_EVS(0, 0, 0, 0, 252, 252),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SP_DEFENSE | F_EV_SPREAD_DEFENSE,"), ".ev = TRAINER_PARTY_EVS(0, 0, 252, 0, 0, 252),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(252, 252, 0, 0, 0, 0),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(252, 0, 0, 252, 0, 0),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(170, 0, 170, 170, 0, 0),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK | F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(170, 170, 0, 170, 0, 0),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_SPEED | F_EV_SPREAD_ATTACK,"), ".ev = TRAINER_PARTY_EVS(0, 252, 0, 252, 0, 0),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_HP,"), ".ev = TRAINER_PARTY_EVS(252, 0, 252, 0, 0, 0),", data)
    data = re.sub(re.escape(".evSpread = F_EV_SPREAD_DEFENSE | F_EV_SPREAD_ATTACK,"), ".ev = TRAINER_PARTY_EVS(0, 252, 252, 0, 0, 0),", data)

    return data

with open('src/data/battle_frontier/battle_frontier_mons.h', 'r') as file:
    data = file.read()
with open('src/data/battle_frontier/battle_frontier_mons.h', 'w') as file:
    file.write(battle_frontier_mons(data))

with open('src/data/battle_frontier/battle_tent.h', 'r') as file:
    data = file.read()
with open('src/data/battle_frontier/battle_tent.h', 'w') as file:
    file.write(battle_frontier_mons(data))
>>>>>>> upstream/master
