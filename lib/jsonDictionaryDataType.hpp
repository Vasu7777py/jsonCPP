
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <string.h>

// dictionary
namespace JSON{
	template<typename DataType, int baseHashTableSize>
	class Dictionary1{
		private:

			template<typename valueType>
			class keyValuePair{
				private:
					std::string key;
					valueType data;
					double hash;

				public:
					
					KeyValuePair(){
						key = "";
						hash = -1;
					}

					keyValuePair(std::string key, double hash){
						this->key = key;
						this->hash = hash;
					}

					void operator=(valueType data){
						if((hash == -1) && (strcmp(key, "") == 0)){
							throw "Invalid keyValuePair!!!\n"
						}
						this->data = data;
					}

			};

			template<typename type>
			struct keyValuePairNode{
				keyValuePairs *prev, *nxt;
				keyValuePair<type> data;

				keyValuePairNode(){
					prev = NULL;
					nxt = NULL;
				}

				keyValuePair getData(){
					return data;
				}
			};
			
			template<typename ListType>
			class keyValuePairList{
				private:
					keyValuePairNode<ListType> *start, *end;
					int size;

				public:
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

					keyValuePairNode find(double hash, std::string key){
						// 
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

			keyValuePair operator[](std::string key){
				double hash = getHashCode(key);
				return this->HashTable[0].append();
			}
	};
}
