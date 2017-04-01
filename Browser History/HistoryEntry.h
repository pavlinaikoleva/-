#pragma once
#ifndef __HISTORY_ENTRY_H__
#define __HISTORY_ENTRY_H__
struct HistoryEntry
{
	int month;
	char URL[200];
};
void printHistoryEntry(HistoryEntry a);
HistoryEntry enterSite();
#endif // !__HISTORY_ENTRY_H__
