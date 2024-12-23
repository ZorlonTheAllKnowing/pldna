#ifndef GUARD_DIPLOMA_H
#define GUARD_DIPLOMA_H

void Task_StartResearchPokedex_FromOverworldMenu(u8 taskId);

#define MAX_MONS_ON_SCREEN 4
#define HIGHEST_MON_NUMBER 2000

enum PokedexPages
{
    LIST_PAGE,
    INFO_PAGE,
};

enum{
    BG_PAGE_CONTENT,
    BG_BOOK_PAGES,
    BG_SCROLLING_LIST,
    BG_BOOK_COVER,
};

#endif // GUARD_DIPLOMA_H
