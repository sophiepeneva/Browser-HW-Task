# Browser-HW-Task

#include<iostream>
#include "BrowserHistory.h"

using namespace std;

int main()
{
	BrowserHistory GoogleChromeHistory(50);
	HistoryEntry Facebook,Youtube,Instagram;
	Facebook.m_month = 4;
	Facebook.setURL("www.facebook.com");
	Instagram.m_month = 4;
	Instagram.setURL("www.instagram.com");
	Youtube.m_month = 9;
	Youtube.setURL("www.youtube.com");
	GoogleChromeHistory.addNewSiteToHistory(Facebook);
	GoogleChromeHistory.addNewSiteToHistory(Instagram);
	GoogleChromeHistory.addNewSiteToHistory(Youtube);
	cout << "The month with the most logs in Google Chrome is : ";
	cout << GoogleChromeHistory.mostActiveMonth() << endl;
	GoogleChromeHistory.removeMostRecent();
	BrowserHistory SafariHistory(50);
	SafariHistory.addNewSiteToHistory(Youtube);
	SafariHistory.addNewSiteToHistoryFromKeyboard();
	cout << "Enter a month for a monthly history display : ";
	int month;
	cin >> month;
	while (month > 12 || month < 1) {
		cout << "Enter a number between 1 and 12 for the month" << endl;
		cin >> month;
	}
	cout<<"The amount of sites opened from Safari for "<<month<<" : " << SafariHistory.monthlyHistory(month) << endl;;
	BrowserHistory* OperaHistory = new BrowserHistory(100);
	OperaHistory = GoogleChromeHistory + SafariHistory;
	OperaHistory->printHistory(); 
	system("pause");

}
