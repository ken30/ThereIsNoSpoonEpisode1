#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/**
* Don't let the machines win. You are humanity's last hope...
**/

int main()
{
	struct SubNode
	{
		int x;
		int y;
	};

	struct Node
	{
		char cell;
		int x;
		int y;
		SubNode rightNode;
		SubNode bottomNode;
	};

	int width; // the number of cells on the X axis
	std::cin >> width; std::cin.ignore();

	int height; // the number of cells on the Y axis
	std::cin >> height; std::cin.ignore();

	Node **mapArray = new Node*[width];

	for (int i = 0; i < width; i++)
	{
		mapArray[i] = new Node[height];
	}

	for (int y = 0; y < height; y++)
	{
		std::string line; // width characters, each either 0 or .
		std::getline(std::cin, line);

		for (int x = 0; x < width; x++)
		{
			std::cerr << line[x];
			mapArray[x][y].cell = line[x];
			mapArray[x][y].x = x;
			mapArray[x][y].y = y;
		}

		std::cerr << std::endl;
	}

	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			//Bottom Node
			bool haveBottomNode = false;

			for (int i = 1; y + i < height; i++)
			{
				if (y + i < height)
				{
					if (mapArray[x][y + i].cell == '0')
					{
						mapArray[x][y].bottomNode.x = x;
						mapArray[x][y].bottomNode.y = y + i;
						haveBottomNode = true;
						break;
					}
				}
			}

			if (!haveBottomNode)
			{
				mapArray[x][y].bottomNode.x = -1;
				mapArray[x][y].bottomNode.y = -1;
			}

			//Right Node
			bool haveRightNode = false;

			for (int i = 1; x + i < width; i++)
			{
				if (x + i<width)
				{
					if (mapArray[x + i][y].cell == '0')
					{
						mapArray[x][y].rightNode.x = x + i;
						mapArray[x][y].rightNode.y = y;
						haveRightNode = true;
						break;
					}
				}
			}

			if (!haveRightNode)
			{
				mapArray[x][y].rightNode.x = -1;
				mapArray[x][y].rightNode.y = -1;
			}
		}
	}

	// Write an action using cout. DON'T FORGET THE "<< endl"
	// To debug: cerr << "Debug messages..." << endl;


	// Three coordinates: a node, its right neighbor, its bottom neighbor
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			if (mapArray[x][y].cell == '0')
			{
				std::cout << mapArray[x][y].x << " " << mapArray[x][y].y << " "
					<< mapArray[x][y].rightNode.x << " " << mapArray[x][y].rightNode.y << " "
					<< mapArray[x][y].bottomNode.x << " " << mapArray[x][y].bottomNode.y << std::endl;
			}
		}
	}
}