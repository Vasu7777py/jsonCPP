
#pragma once

#include <iostream>
#include <fstream>
#include <string>

namespace JSON{
	template<typename Type>
	class List{
		private:
			Type *data;
			int size;

		public:
			List(){
				data = NULL;
				size = -1;
			}		

			void append(Type data){
				if(size == -1){
					this->data = (Type*) malloc(sizeof(Type));
				}else{
					this->data = (Type*) realloc(this->data, (sizeof(Type)*(size + 1)));
				}
				this->data[++size] = data;
			}
			void removeByData(Type data){}
			void removeByIndex(int index){}
			
			Type operator[](int index){
				if(index > size){
					throw "Index out of bound!!\n";
				}
				try{
					return data[index];
				}catch (const char* msg){
					throw msg;
				}
			}

			std::string getType(){
				return "List";
			}
	};
}

