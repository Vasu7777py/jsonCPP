
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

// dictionary
namespace JSON{
	template<typename DataType, int baseHashTableSize>
	class Dictionary{
		private:

			template<typename valueType>
			struct keyValuePairNode{
				keyValuePairs *prev, *nxt;
				std::string key;
				valueType data;
				double hash;

				keyValuePairNode(){
					prev = NULL;
					nxt = NULL;
				}

				valueType getData(){
					return data;
				}
			};
			
			template<typename ListType>
			struct keyValuePairList{
				keyValuePairNode<ListType> *start, *end;
				int size;

				keyValuePairList(){
					start = NULL;
					end = NULL;
				}

				void append(keyValuePairNode<ListType> *node){
					if(start == NULL){
						start = node;
					}
					if(end != NULL){
						end->nxt = node;
						node->prev = end;
					}
					end = node;
					++size;
				}
			};
			
			keyValuePairList<DataType> HashTable[baseHashTableSize];

		public:
			// Dictionary();

			double getHashCode(const std::string string){
				double hash = 1, constant = 47;
				for(int i = 0; i < string.size(); i++){
					hash = (constant * hash) + (double)string[i];
				}
				return hash;
			}

			std::string getType(){
				return "Dictionary";
			}
	};
}
