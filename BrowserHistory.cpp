# Browser-HW-Task

#include "BrowserHistory.h"
#include<string.h>
#include<iostream>


BrowserHistory::BrowserHistory(int N)
{
	m_N = N;
	m_sitesAmount = 0;
	m_history = new HistoryEntry[m_N];
}

BrowserHistory::~BrowserHistory()
{
	delete[] m_history;
}

void BrowserHistory::addNewSiteToHistoryFromKeyboard()
{
	if (m_sitesAmount + 1 <= m_N)
	{
		std::cout << "Enter the  month in which the site was visited" << std::endl;
		std::cin >> m_history[m_sitesAmount].m_month;
		std::cout << "Enter the  url of the site" << std::endl;
		std::cin >> m_history[m_sitesAmount++].m_url;
	}
	else
	{
		std::cout << "Error : Histry memory is full" << std::endl;
	}
}

void BrowserHistory::addNewSiteToHistory(const HistoryEntry& newSite)
{
	if (m_sitesAmount + 1 <= m_N)
	{
		m_history[m_sitesAmount].m_month = newSite.m_month;
		m_history[m_sitesAmount++].m_url = newSite.m_url;
	}
	else
	{
		std::cout << "Error : Histry memory is full" << std::endl;
	}
}

void BrowserHistory::printHistory() const 
{
	for (int i = 0;i < m_sitesAmount;i++)
	{
		std::cout << "URL : " << m_history[i].m_url << " month : " << m_history[i].m_month << std::endl;
	}
}

int BrowserHistory::monthlyHistory(int month) const
{
	int counter = 0;
	for (int i = 0;i < m_sitesAmount;i++)
	{
		if (m_history[i].m_month == month)counter++;
	}
	return counter;
}

int BrowserHistory::mostActiveMonth() const
{
	int max, current, counter = 1, maxIndex = 0;
	max = monthlyHistory(counter++);
	current = monthlyHistory(counter++);
	//Here I use the ladder method in order to estimate which month has the  most logs
	while(counter < 13)
	{
		if (current > max) 
		{
			max = current;
			maxIndex = counter-1;
		}
		current = monthlyHistory(counter++);
	}
	return maxIndex;
}

void BrowserHistory::removeMostRecent() 
{
	if (m_sitesAmount == 0)std::cout << "Error : history is empty" << std::endl;
	if(m_sitesAmount > 0)
	{
		m_sitesAmount--;
	}
}

BrowserHistory* BrowserHistory::operator+(const BrowserHistory& bH)const
{
	//This method overloads the operator '+' in order to concatenade two Browser histories
	BrowserHistory * newBrowser = new BrowserHistory(m_sitesAmount + bH.m_sitesAmount);
	for (int i = 0;i < m_sitesAmount;i++)
	{
		newBrowser->addNewSiteToHistory(m_history[i]);
	}
	for (int i = 0;i <bH.m_sitesAmount;i++)
	{
		newBrowser->addNewSiteToHistory(bH.m_history[i]);
	}

	return newBrowser;
}
