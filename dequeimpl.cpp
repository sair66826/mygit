#include<iostream>
using namespace std;
class deque
{
	int table_size=4;
	int block_size=4;
	int **block_table;
	int start_offset;
	int end_offset;
	int start_block;
	int end_block;
	int current_size;
	public:
	  deque()
	  {
		 block_table=new int*[table_size];
		 for(int i=0;i<table_size;i++)
			 block_table[i]=nullptr;
		 block_table[table_size/2]=new int[block_size];
		 start_block=end_block=table_size/2;
		 start_offset=end_offset=0;
		 current_size=0;
	  }
	  void realloc()
	  {
		  int **newblock=new int*[table_size*2];
		  int news=table_size/2;
		  int j=start_block+news;
		  for(int i=start_block;i<=end_block;i++)
		  {
			  newblock[j++]=block_table[i];
		  }
		  start_block+=table_size/2;
		  end_block+=table_size/2;
		  table_size*=2;
		  delete []block_table;
		  block_table=newblock;
	  }
	  void push_back(int val)
	  {
		  if((end_block==table_size-1)&&(end_offset==block_size))
		  {
			  realloc();
		  }
		  if(end_offset==block_size)
		  {
			  end_block++;
			  block_table[end_block]=new int[block_size];
			  end_offset=0;
		  }
		  block_table[end_block][end_offset++]=val;
		  current_size++;
	  }
	  void push_front(int val)
	  {
		  if(start_block==0&&start_offset==0)
		  {
			  realloc();
		  }
		  if(start_offset==0)
		  {
			  start_block--;
			  block_table[start_block]=new int[block_size];
			  start_offset=block_size;
		  }
		  start_offset--;
		  block_table[start_block][start_offset]=val;
		  current_size++;
	  }
	  T& operator[](int index)
	  {
		  int table_offset=start_offset+index;
		  int block=start_block+(table_offset/block_size);
		  int offset=(table_offset%block_size);
		  return block_table[block][offset];
	  }
};
