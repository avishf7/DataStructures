#pragma once
#include <list>
#include<string>
#include "MyHashTable.h"

using namespace std;

class HSubject : public MyHashTable<list<string>,string>
{
};

