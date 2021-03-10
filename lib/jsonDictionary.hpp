
#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>

namespace JSON{

	double getHashCode(std::string string){
		double hash = 1, constant = 47;
		for(int i = 0; i < string.size(); i++){
			hash = (constant * hash) + (double)string[i];
		}
		return hash;
	}

	template<typename dataType>
	class keyValuePair{
		private:
			std::string key;
			double hash;
			dataType value;

		public:

			keyValuePair(){
				key = "";
				hash = -1;
			}

			keyValuePair(std::string key, dataType value){
				this->key = key;
				this->value = value;
				this->hash = getHashCode(key);
			}

			bool isValid(){
				if((key == "") && (hash == -1)){
					return true;
				}
				return false;
			}

			void operator=(dataType value){
				if(!isValid()){
					throw "key value pair not valid!!\n";
				}
				this->value = value;
			}

			bool keyCompare(std::string cpmKey){
				if(key == cpmKey){
					return true;
				}
				return false;
			}

			std::ostream& operator<<(std::ostream& stream){
				stream << "{ " << key << " : ";
				stream << value;
				stream << " }";
				return stream;
			}

	};
	
	template<typename dataType>
	class KVP_List{
		private:
			
			template<typename type>
			struct node{
				node *prev, *nxt;
				keyValuePair<type> data;

				node(){
					prev = NULL;
					nxt = NULL;
					data = keyValuePair<type>();
				}

				node(std::string string, type value){
					prev = NULL;
					nxt = NULL;
					data = keyValuePair<type>(string, value);
				}

			};

			node<dataType> *start, *end;
		
		public:

			KVP_List(){
				start = NULL;
				end = NULL;
			}

			void append(std::string string, dataType value){
				node<dataType> *nKVP = new node<dataType>(string, value);
				if(start == NULL){
					start = nKVP;
				}
				if(end != NULL){
					end->nxt = nKVP;
					nKVP->prev = end;
				}
				end = nKVP;
			}

			const keyValuePair<dataType>& find(std::string key){
				node<dataType> *probe = start;
				while (probe != NULL){
					if(probe->data->keyCompare(key) == true){
						return &(probe->data);
					}
					return NULL;
				}
			}

			std::ostream& operator<<(std::ostream& stream){
				node<dataType> *probe = start;
				while (probe != NULL){
					stream << (probe->data);
					stream << ",\n";
				}
				return stream;
			} 

	};
	
	template<typename dataType, int hashTableSize>
	class Dictionary{
		private:
			std::vector<KVP_List<dataType>> hashTable;
		public:

			Dictionary(){
				hashTable.reserve(hashTableSize);
				for(int i = 0; i < hashTableSize; i++){
					KVP_List<dataType>& cell = hashTable[i];
					cell = KVP_List<dataType>();
				}
			}

			const keyValuePair<dataType>& operator[](std::string key){
				double hash = getHashCode(key);
				int indexHash = (int) hash/hashTableSize;
				KVP_List<dataType> cell = hashTable[indexHash];
				keyValuePair<dataType> *kvp = cell.find(key);
				return kvp;
			}

			void operator()(std::string key, dataType value){
				double hash = getHashCode(key);
				int indexHash = (int) hash/hashTableSize;
				KVP_List<dataType> cell = hashTable[indexHash];
				cell.append(key, value);
			}

			std::ostream& operator<<(std::ostream& stream){
				for(KVP_List<dataType> cell : hashTable){
					stream << cell;
					stream << ",\n";
				}
				return stream;
			}
	};
}
