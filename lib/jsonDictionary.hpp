
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>

namespace JSON{

	template<typename dataType>
	class keyValuePair{
		private:
		public:
	};

	template<typename dataType>
	class KVP_List{
		private:
			dataType *start, *end;

			struct node{
				node *prev, *nxt;
				keyValuePair<dataType> data;
			};
		
		public:

			KVP_List(){
				start = NULL;
				end = NULL;
			}
	};
	
	template<typename dataType, int hashTableSize>
	class Dictionary{
		private:
			std::vector<KVP_List<dataType>> hashTable;
		public:

			Dictionary(){
				hashTable.reserve(hashTableSize);
			}
	};

	double getHashCode(std::string string){
		double hash = 1, constant = 47;
		for(int i = 0; i < string.size(); i++){
			hash = (constant * hash) + (double)string[i];
		}
		return hash;
	}
}
