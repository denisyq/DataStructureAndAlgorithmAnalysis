#include<list>

//cons
std::list<int> list;
std::list<int> list(8,10);
std::list<int> list(first.begin(),first.end());
std::list<int> list(second);

//iterator
list.begin();
list.rbegin();
list.end();
list.rend();

//capacity
list.size();
list.empty();
	//resize
	//list = [1,2,3,4,5,6]
	list.resize(3);		//[1,2,3]
	list.resize(5,10)	//[1,2,3,10,10]

//element access
list.front();
list.back();


//element modify
	//assign
	list.assign(5,10);
	list.assign(first.begin(),first.end());
	//push/pop
	list.push_back();
	list.push_front();
	list.pop_back();
	list.pop_front();

	//insert
	list.insert(list.begin(),1);
	list,insert(list.begin(),10,1);
	list.insert(list.begin(),second.begin(),second.end());
	
	//erase
	list.erase(list.begin());
	list.erase(list.begin(),list.begin()+3);

	//swap
	list.swap(first);
	//clear
	list.clear();


//others
	//splice
	list.splice(list.begin(),second,second.begin());		//splice single element
	list.splice(list.begin(),second.begin(),second.end());
	list.splice(second);

	//remove
	list.remove(100);		//100 is value, remove 100













