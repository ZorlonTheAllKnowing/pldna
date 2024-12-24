#ifndef GUARD_DIPLOMA_H
#define GUARD_DIPLOMA_H

void Task_StartResearchPokedex_FromOverworldMenu(u8 taskId);

#define MAX_MONS_ON_SCREEN 4
#define HIGHEST_MON_NUMBER 2000

enum PokedexPages
{
    LIST_PAGE,
    INFO_PAGE,
    STAT_PAGE,
    AREA_PAGE,
    TASK_PAGE,
    FORM_PAGE,
    MOVE_PAGE,
};

enum{
    LIST_PAGE_BG0,
    LIST_PAGE_BG1,
    LIST_PAGE_BG2,
    LIST_PAGE_BG3,
};

#endif // GUARD_DIPLOMA_H
