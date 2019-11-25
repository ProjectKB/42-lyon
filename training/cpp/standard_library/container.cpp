/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   container.cpp                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: loiberti <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/25 15:54:19 by loiberti     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/25 16:44:06 by loiberti    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <string>
#include <iostream>

// Sequency
#include <vector>
#include <deque>
#include <list>
#include <stack>
#include <queue>

// Associative Container
#include <set>
#include <map>

/*
Shared method for string, vector, map, list
-> size()
-> empty()
-> clear() : clear container
-> swap()

Shared method for every sequency container
-> push_back(x), pop_back()
-> front(), back()
-> assign(x) : set every elems with x

*/

using namespace std;
using str = string;

void	double_ended_tail_()
{
	deque<int> dq;

	dq = {10, -4, 7};
	dq.push_back(47);
	dq.push_front(48);
	cout << "start: " << dq.front() << " | end: " << dq.back() << "\n";
	dq.pop_back();
	dq.pop_front();
	cout << "start: " << dq.front() << " | end: " << dq.back() << "\n";

	// Inconvenient : Each time you pop_front every index have to be moove
}

void	stack_lifo() // last in first out
{
	stack<int> pile;

	pile.push(3);
	pile.push(4);
	pile.push(5);

	cout << pile.top() << " ";
	pile.pop();
	cout << pile.top() << "\n";

	// You can only use top/pop/push.
}

void	queue_fifo() // first in first out
{
	queue<int> pile;

	pile.push(3);
	pile.push(4);
	pile.push(5);

	cout << pile.front() << " ";
	pile.pop();
	cout << pile.front() << "\n";

	// You can only use front/pop/push.
}

void	priority_queue_ex() // sorted in ascending order
{
	priority_queue<int> pile;

	pile.push(68);
	pile.push(1000);
	pile.push(2000);
	pile.push(-8);

	cout << pile.top() << " ";
	pile.pop();
	cout << pile.top() << "\n";

	// You can only use top/pop/push.
}

int main()
{
	str test;

	//double_ended_tail_();
	stack_lifo();
	queue_fifo();
	priority_queue_ex();
	return (0);
}
