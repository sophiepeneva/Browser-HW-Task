# Browser-HW-Task

#ifndef BROWSERHISTORY_H
#define BROWSERHISTORY_H

#include<string>

struct HistoryEntry{
	enum{MAX_LENGHT_URL=50};
	int m_month;
	char* m_url = new char[MAX_LENGHT_URL];
	void setURL(const char* url) {
		strcpy_s(m_url, strlen(url) + 1, url);
	}
};

class BrowserHistory
{
public:
	BrowserHistory(int N);
	~BrowserHistory();

	void addNewSiteToHistoryFromKeyboard();
	void addNewSiteToHistory(const HistoryEntry&);

	int monthlyHistory(int month)const;
	int mostActiveMonth()const;
	BrowserHistory* operator+(const BrowserHistory& bH)const;
	void printHistory() const;

	void removeMostRecent();
private:
	int m_N;
	int m_sitesAmount;
	HistoryEntry* m_history = new HistoryEntry[m_N];
};
#endif

