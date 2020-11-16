#ifndef Item_h
#define Item_h



enum state { empty, full, deleted };

template <class T, class K>
class Item
{
public:
	T data;
	K key;
	state flag;
	Item() {}
	Item(T d, K k, state f) { data = d; key = k; flag = f; }
};

#endif // !Item_h