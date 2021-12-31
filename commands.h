#pragma once
#include <iostream>
#include "Items.h"
#include "TextParsing.h"

items* item = new items();
text* parse = new text();

class commands {
	public:
		
		//pos is position
		struct pos {
			int x;
			int y;

			static pos to_pos(int x, int y) {
				return { x,y };
			}

			bool operator==(pos other) {
				return x == other.x && y == other.y;
			};
		};
				
		inline void instructions(){
			
			std::cout << std::endl;
			std::cout << "--------------------------------------------------------------" << std::endl;
			std::cout << "INSTRUCTIONS" << std::endl;
			std::cout << "Type in cardinal directions to move (NORTH, SOUTH, EAST, WEST) or (N, S, E, W)" << std::endl;
			std::cout << std::endl;
			std::cout << "*List of commands*" << std::endl;
			std::cout << ">open" << std::endl;
			std::cout << ">use" << std::endl;
			std::cout << ">buy" << std::endl;
			std::cout << ">sell" << std::endl;
			std::cout << std::endl;
			std::cout << "Enter 'Inventory' in order to open inventory" << std::endl;
			std::cout << "Enter '?' in order to print instructions" << std::endl;
			std::cout << "--------------------------------------------------------------" << std::endl;
			std::cout << std::endl;
		}	
		
		//userSpace is where the player will be able to enter commands
		inline pos userSpace(int x, int y){
	
			std::string command;
			
			std::cout << "\n>>> ";
			std::getline(std::cin, command);
			command = parse->lowerCase(command);
			std::cout << std::endl;
			
			parse->parsing(command);
			std::string order = parse->order;
			std::string object = parse->object;
			
			//inventory
			if (order == "inventory") {
				item->inventory();
			}

			//Instructions
			else if(order == "?"){
				instructions();
			}

			//Directions
			else if(order == "north" || order == "n") {
				y++;
			}
			else if(order == "south" || order == "s"){
				y--;
			}
			else if(order == "east" || order == "e"){
				x++;
			}
			else if(order == "west" || order == "w"){
				x--;
			}

			//Open
			else if (order == "open") {
				if (object == "chest") {
					if (item->chest_proximity == true && item->cave_chest == false) {
						std::cout << "You opened the chest!" << std::endl;
						std::cout << "Inside was a sack of coins" << std::endl;
						std::cout << "You've earned 100G" << std::endl;
						item->gold_amount += 100;
						item->cave_chest = true;
					}
					else if (item->chest_proximity == true && item->cave_chest == true) {
						std::cout << "The chest is empty" << std::endl;
					}

					else if (item->chest_proximity == false) {
						std::cout << "What chest?" << std::endl;
					}
				}
				else if (object == "") {
					std::cout << "Open what?" << std::endl;
				}
				else {
					std::cout << "You can't open \"" << object << "\" in Slash Quest" << std::endl;
				}
			}

			//Use
			else if (order == "use") {
				if (object == "placeholder") {
					std::cout << "Thumbs up" << std::endl;
				}
				else if (object == "") {
					std::cout << "Use what?" << std::endl;
				}
				else {
					std::cout << "You can't use \"" << object << "\" in Slash Quest" << std::endl;
				}
			}
			else if (order == "buy") {
				if (item->shop == false) {
					std::cout << "Transactions cannot be made outside of a shop" << std::endl;
				}
			}

			else if (order == "sell") {
				if (item->shop == false) {
					std::cout << "Transactions cannot be made outside of a shop" << std::endl;
				}
			}

			else {

				std::cout << "Invalid Command!" << std::endl;
			}
		
			return {x,y};
		}
		
		inline void cave_chest() {
			

		}
	
};