#include "main.h"




//main method where all functions will take place
int main()
{
	Assn3Driver* ThemDriverbaby = new Assn3Driver();
	ThemDriverbaby->main();
	return 0;
}

void Assn3Driver::main()
{
	std::cout << "Student Number: " << s_Student_Number << endl;
	std::cout << "Student Name: " << s_Student_Name << endl;
	std::cout << "--------------------------------------------" << endl;
	print_Menu();
}

void Assn3Driver::print_Menu()
{
	int choice;
	std::cout << "Welcome to the Assignment 3 Program!" << endl << endl << endl;
	std::cout << "1) Read in Data" << endl;
	print_current_state();
	std::cout << endl << endl;
	std::cout << "Please enter choice: ";
	std::cin >> choice;

	switch (choice)
	{
	case 1:
		read_txt_file();
		break;
	case 2:
		swap_filtering_Criteria();
		break;
	case 3:
		swap_sorting_Criteria();
		break;
	case 4:
		swap_asc_desc_Criteria();
		break;
	case 5:
		print_Data();
		break;
	case 6:
		write_txt_file();
		break;
	case 7:
		exit(0);
		break;
	}
	main();
}

void Assn3Driver::read_txt_file()
{
	p2d_unique_entries = 0;
	p3d_unique_entries = 0;
	l2d_unique_entries = 0;
	l3d_unique_entries = 0;
	string readabletxt;
	int counter = 0;
	std::cout << "Enter text file:";
	std::cin >> readabletxt;

	fstream inputFile(readabletxt.c_str(), fstream::in);

	string aLine;
	std::cout << endl;
	while (getline(inputFile, aLine))
	{
		if (aLine.size() > 0)
		{
			//size_t countofinstance = count(aLine.begin(), aLine.end(), ", [");
			int occurences = 0;
			size_t pos = 0;
			string target = ", [";
			while ((pos = aLine.find(target, pos)) != string::npos)
			{
				++occurences;
				pos += target.length();
			}

			if (occurences == 1)
			{
				aLine.erase(aLine.find('['), 1);
				aLine.erase(aLine.find(']'), 1);
				vector<string> token_vector = tokenize_string(aLine, ", ");
				if (token_vector.size() == 3)
				{
					int temp_x, temp_y;
					stringstream(token_vector[1]) >> temp_x;
					stringstream(token_vector[2]) >> temp_y;
					Point2D temp_p2d = Point2D(temp_x, temp_y);
					if (v_p2d_container.size() != 0)
					{
						bool flag = false;
						for (int i = 0; i < v_p2d_container.size(); i++)
						{
							if (v_p2d_container[i].getX() == temp_x
								&& v_p2d_container[i].getY() == temp_y)
							{
								flag = true;
								break;
							}
						}
						if (!flag)
						{
							v_p2d_container.push_back(temp_p2d);
							counter++;
							p2d_unique_entries++;
						}
					}
					else
					{
						v_p2d_container.push_back(temp_p2d);
						counter++;
						p2d_unique_entries++;
					}

				}
				else if (token_vector.size() == 4)
				{
					int temp_x, temp_y, temp_z;
					stringstream(token_vector[1]) >> temp_x;
					stringstream(token_vector[2]) >> temp_y;
					stringstream(token_vector[3]) >> temp_z;
					Point3D temp_p3d = Point3D(temp_x, temp_y,temp_z);
					if (v_p3d_container.size() != 0)
					{
						bool flag = false;
						for (int i = 0; i < v_p3d_container.size(); i++)
						{
							if (v_p3d_container[i].getX() == temp_x
								&& v_p3d_container[i].getY() == temp_y
								&& v_p3d_container[i].getZ() == temp_z)
							{
								flag = true;
								break;
							}
						}
						if (!flag)
						{
							v_p3d_container.push_back(temp_p3d);
							counter++;
							p3d_unique_entries++;
						}
					}
					else
					{
						v_p3d_container.push_back(temp_p3d);
						counter++;
						p3d_unique_entries++;
					}
				}
			}
			else if (occurences == 2)
			{
				aLine.erase(aLine.find('['), 1);
				aLine.erase(aLine.find('['), 1);
				aLine.erase(aLine.find(']'), 1);
				aLine.erase(aLine.find(']'), 1);
				vector<string> token_vector = tokenize_string(aLine, ", ");
				if (token_vector.size() == 5)
				{
					int temp_x, temp_y;
					stringstream(token_vector[1]) >> temp_x;
					stringstream(token_vector[2]) >> temp_y;
					Point2D temp_p2d =Point2D(temp_x, temp_y);

					int temp_x2, temp_y2;
					stringstream(token_vector[3]) >> temp_x2;
					stringstream(token_vector[4]) >> temp_y2;
					Point2D temp_p2d2 =  Point2D(temp_x2, temp_y2);

					Line2D temp_l2d = Line2D(temp_p2d,temp_p2d2);
					if (v_l2d_container.size() != 0)
					{
						bool flag = false;
						for (int i = 0; i < v_l2d_container.size(); i++)
						{
							if (v_l2d_container[i].getPt1().getX() == temp_x &&
								v_l2d_container[i].getPt1().getY() == temp_y &&
								v_l2d_container[i].getPt2().getX() == temp_x2 &&
								v_l2d_container[i].getPt2().getY() == temp_y2)
							{
								flag = true;
								break;
							}
						}
						if (!flag)
						{
							v_l2d_container.push_back(temp_l2d);
							counter++;
							l2d_unique_entries++;
						}
					}
					else
					{
						v_l2d_container.push_back(temp_l2d);
						counter++;
						l2d_unique_entries++;
					}
				}
				else if (token_vector.size() == 7)
				{
					int temp_x, temp_y, temp_z;
					stringstream(token_vector[1]) >> temp_x;
					stringstream(token_vector[2]) >> temp_y;
					stringstream(token_vector[3]) >> temp_z;
					Point3D temp_p3d = Point3D(temp_x, temp_y, temp_z);

					int temp_x2, temp_y2, temp_z2;
					stringstream(token_vector[4]) >> temp_x2;
					stringstream(token_vector[5]) >> temp_y2;
					stringstream(token_vector[6]) >> temp_z2;
					Point3D temp_p3d2 = Point3D(temp_x2, temp_y2, temp_z2);

					Line3D temp_l3d =Line3D(temp_p3d, temp_p3d2);
					if (v_l3d_container.size() != 0)
					{
						bool flag = false;
						for (int i = 0; i < v_l3d_container.size(); i++)
						{
							if (v_l3d_container[i].getPt1().getX() == temp_x &&
								v_l3d_container[i].getPt1().getY() == temp_y &&
								v_l3d_container[i].getPt1().getZ() == temp_z &&
								v_l3d_container[i].getPt2().getX() == temp_x2 &&
								v_l3d_container[i].getPt2().getY() == temp_y2 &&
								v_l3d_container[i].getPt2().getZ() == temp_z2)
							{
								flag = true;
								break;
							}
						}
						if (!flag)
						{
							v_l3d_container.push_back(temp_l3d);
							counter++;
							l3d_unique_entries++;
						}
					}
					else
					{
						v_l3d_container.push_back(temp_l3d);
						counter++;
						l3d_unique_entries++;
					}
				}
			}
		}
	}
	cout << counter << " records were updated" << endl << endl << endl;
}

void Assn3Driver::print_current_state()
{
	std::cout << "2) Specify Filtering Criteria: ";
	switch (machinestate.i_filter_Criteria)
	{
	case 0:
		std::cout << machinestate.s_filter_Criteria[machinestate.i_filter_Criteria] << endl;
		std::cout << "3) Specify Sorting Criteria " << machinestate.s_point2D_sort[machinestate.i_point2D_Sort];
		std::cout << endl;
		std::cout << "4) Specify sorting order " << machinestate.s_Asc_Desc_sort[machinestate.i_Asc_Desc_sort];
		break;
	case 1:
		std::cout << machinestate.s_filter_Criteria[machinestate.i_filter_Criteria] << endl;
		std::cout << "3) Specify Sorting Criteria " << machinestate.s_point3D_sort[machinestate.i_point3D_Sort];
		std::cout << endl;
		std::cout << "4) Specify sorting order " << machinestate.s_Asc_Desc_sort[machinestate.i_Asc_Desc_sort];
		break;
	case 2:
		std::cout << machinestate.s_filter_Criteria[machinestate.i_filter_Criteria] << endl;
		std::cout << "3) Specify Sorting Criteria " << machinestate.s_Line_sort[machinestate.i_Line_sort];
		std::cout << endl;
		std::cout << "4) Specify sorting order " << machinestate.s_Asc_Desc_sort[machinestate.i_Asc_Desc_sort];
		break;
	case 3:
		std::cout << machinestate.s_filter_Criteria[machinestate.i_filter_Criteria] << endl;
		std::cout << "3) Specify Sorting Criteria " << machinestate.s_Line_sort[machinestate.i_Line_sort];
		std::cout << endl;
		std::cout << "4) Specify sorting order " << machinestate.s_Asc_Desc_sort[machinestate.i_Asc_Desc_sort];
		break;
	default:
		break;
	}
	std::cout << endl;
	std::cout << "5) View Data" << endl;
	std::cout << "6) Store Data" << endl;
	std::cout << "7) Exit" << endl;
}

void Assn3Driver::print_Data()
{
	//Point 2D
	if (machinestate.i_filter_Criteria == 0)
	{
		//Sort by X
		if (machinestate.i_point2D_Sort == 0)
		{
			//Ascending
			if (machinestate.i_Asc_Desc_sort == 0)
			{
				global_oss = print_Point_2D(true, false, true);
			}
			else //Descending
			{
				global_oss = print_Point_2D(true, false, false);
			}
		}
		//Sort by Y
		if (machinestate.i_point2D_Sort == 1)
		{
			//Ascending
			if (machinestate.i_Asc_Desc_sort == 0)
			{
				global_oss = print_Point_2D(false, false, true);
			}
			else //Descending
			{
				global_oss = print_Point_2D(false, false, false);
			}
		}
		//Sort by Length
		if (machinestate.i_point2D_Sort == 2)
		{
			//Ascending
			if (machinestate.i_Asc_Desc_sort == 0)
			{
				global_oss = print_Point_2D(false, true, true);
			}
			else //Descending
			{
				global_oss = print_Point_2D(false, true, false);
			}
		}
	}
	//point 3D
	if (machinestate.i_filter_Criteria == 1)
	{
		//sort by X
		if (machinestate.i_point3D_Sort == 0)
		{
			//global_oss = print_Point_3D(true, false, false, false, false);
			if (machinestate.i_Asc_Desc_sort == 0)
			{
				global_oss = print_Point_3D(true, false, false, false, true);
			}
			else //Descending
			{
				global_oss = print_Point_3D(true, false, false, false, false);
			}
		}
		//sort by Y
		if (machinestate.i_point3D_Sort == 1)
		{
			//global_oss = print_Point_3D(true, false, false, false, false);
			if (machinestate.i_Asc_Desc_sort == 0)
			{
				global_oss = print_Point_3D(false, true, false, false, true);
			}
			else //Descending
			{
				global_oss = print_Point_3D(false, true, false, false, false);
			}
		}
		//sort by Z
		if (machinestate.i_point3D_Sort == 2)
		{
			//global_oss = print_Point_3D(true, false, false, false, false);
			if (machinestate.i_Asc_Desc_sort == 0)
			{
				global_oss = print_Point_3D(false, false, true, false, true);
			}
			else //Descending
			{
				global_oss = print_Point_3D(false, false, true, false, false);
			}
		}
		//sort by length
		if (machinestate.i_point3D_Sort == 3)
		{
			//global_oss = print_Point_3D(true, false, false, false, false);
			if (machinestate.i_Asc_Desc_sort == 0)
			{
				global_oss = print_Point_3D(false, false, false, true, true);
			}
			else //Descending
			{
				global_oss = print_Point_3D(false, false, false, true, false);
			}
		}
	}
	//Line2D
	if (machinestate.i_filter_Criteria == 2)
	{
		if (machinestate.i_Line_sort == 0)
		{
			if (machinestate.i_Asc_Desc_sort == 0)
			{
				global_oss = print_Line_Data(true, true, false, false, true);
			}
			else //Descending
			{
				global_oss = print_Line_Data(true, true, false, false, false);
			}
		}
		if (machinestate.i_Line_sort == 1)
		{
			if (machinestate.i_Asc_Desc_sort == 0)
			{
				global_oss = print_Line_Data(true, false, true, false, true);
			}
			else //Descending
			{
				global_oss = print_Line_Data(true, false, true, false, false);
			}
		}
		if (machinestate.i_Line_sort == 2)
		{
			if (machinestate.i_Asc_Desc_sort == 0)
			{
				global_oss = print_Line_Data(true, false, false, true, true);
			}
			else //Descending
			{
				global_oss = print_Line_Data(true, false, false, true, false);
			}
		}
	}
	//Line 3D
	if (machinestate.i_filter_Criteria == 3)
	{
		if (machinestate.i_Line_sort == 0)
		{
			if (machinestate.i_Asc_Desc_sort == 0)
			{
				global_oss = print_Line_Data(false, true, false, false, true);
			}
			else //Descending
			{
				global_oss = print_Line_Data(false, true, false, false, false);
			}
		}
		if (machinestate.i_Line_sort == 1)
		{
			if (machinestate.i_Asc_Desc_sort == 0)
			{
				global_oss = print_Line_Data(false, false, true, false, true);
			}
			else //Descending
			{
				global_oss = print_Line_Data(false, false, true, false, false);
			}
		}
		if (machinestate.i_Line_sort == 2)
		{
			if (machinestate.i_Asc_Desc_sort == 0)
			{
				global_oss = print_Line_Data(false, false, false, true, true);
			}
			else //Descending
			{
				global_oss = print_Line_Data(false, false, false, true, false);
			}
		}
	}
	cout << global_oss;
}

void Assn3Driver::swap_filtering_Criteria()
{
	std::cout << endl << endl;
	std::cout << "[Specifying filtering Criteria" << machinestate.s_filter_Criteria[machinestate.i_filter_Criteria] << "]" << endl;
	std::cout << "1) Point2D records" << endl;
	std::cout << "2) Point3D records" << endl;
	std::cout << "3) Line2D records" << endl;
	std::cout << "4) Line3D records" << endl;

	std::cout << "Enter your criteria (1 - 4): ";
	int i;
	std::cin >> i;
	machinestate.i_filter_Criteria = i - 1;
	std::cout << "Criteria swapped!" << machinestate.s_filter_Criteria[machinestate.i_filter_Criteria] << endl;
}

void Assn3Driver::swap_sorting_Criteria()
{
	if (machinestate.i_filter_Criteria == 0)
	{
		std::cout << "[Specifying sorting criteria, current: " << machinestate.s_point2D_sort[machinestate.i_point2D_Sort] << "]" << endl;
		std::cout << "1) Sort by X coordinate" << endl;
		std::cout << "2) Sort by Y coordinate" << endl;
		std::cout << "3) Sort by distance to Origin" << endl;
		std::cout << "Enter your criteria (1 - 3): ";
		int i;
		std::cin >> i;
		machinestate.i_point2D_Sort = i - 1;
		std::cout << "Criteria Swapped to: " << machinestate.s_point2D_sort[machinestate.i_point2D_Sort] << endl;
	}
	else if (machinestate.i_filter_Criteria == 1)
	{
		std::cout << "[Specifying sorting criteria, current: " << machinestate.s_point2D_sort[machinestate.i_point2D_Sort] << "]" << endl;
		std::cout << "1) Sort by X coordinate" << endl;
		std::cout << "2) Sort by Y coordinate" << endl;
		std::cout << "3) Sort by Z coordinate" << endl;
		std::cout << "4) Sort by distance to Origin" << endl;
		std::cout << "Enter your criteria (1 - 4): ";
		int i;
		std::cin >> i;
		machinestate.i_point3D_Sort = i - 1;
		std::cout << "Criteria Swapped to: " << machinestate.s_point3D_sort[machinestate.i_point3D_Sort] << endl;

	}
	else if (machinestate.i_filter_Criteria == 2 || machinestate.i_filter_Criteria == 3)
	{
		std::cout << "[Specifying sorting criteria, current: " << machinestate.s_Line_sort[machinestate.i_Line_sort] << "]" << endl;
		std::cout << "1) Point 1 (X,Y coordinates)" << endl;
		std::cout << "2) Point 2 (X,Y coordinates)" << endl;
		std::cout << "3) Length of Line" << endl;
		std::cout << "Enter your criteria (1 - 3): ";
		int i;
		std::cin >> i;
		machinestate.i_Line_sort = i - 1;
		std::cout << "Criteria Swapped to: " << machinestate.s_Line_sort[machinestate.i_Line_sort] << endl << endl;

	}
}

void Assn3Driver::swap_asc_desc_Criteria()
{
	std::cout << "[Specifying sorting criteria, current: " << machinestate.s_Asc_Desc_sort[machinestate.i_Asc_Desc_sort] << "]" << endl;
	std::cout << "1) Ascending" << endl;
	std::cout << "2) Descending" << endl;
	std::cout << "Enter your criteria (1 - 2): ";
	int i;
	std::cin >> i;
	machinestate.i_Asc_Desc_sort = i - 1;
	std::cout << "Criteria Swapped to: " << machinestate.s_Asc_Desc_sort[machinestate.i_Asc_Desc_sort] << endl << endl;

}


string Assn3Driver::print_Point_2D(bool X_coord, bool length,bool ascend)
{
	ostringstream oss;
	oss << "Filtering by: Point2D" <<endl;
	if (X_coord && !length)
	{
		oss << "Sort by: X coordinate" << endl;
		sort(v_p2d_container.begin(), v_p2d_container.end(),
			[](Point2D lhs, Point2D rhs)
			{
				return lhs.getX() > rhs.getX();
			});
		if (!ascend)
		{
			oss << "Sorting order: Descending" << endl;
			for (int i = 0; i < v_p2d_container.size(); i++)
			{
				oss << v_p2d_container[i] << endl;
			}
		}
		else
		{
			oss << "Sorting order: Ascending" << endl;
			for (int i = v_p2d_container.size() - 1; i >= 0; i--)
			{
				oss << v_p2d_container[i] << endl;
			}
		}
	}
	else if (!X_coord && !length)
	{
		oss << "Sort by: Y coordinate" << endl;
		sort(v_p2d_container.begin(), v_p2d_container.end(),
			[](Point2D lhs, Point2D rhs)
			{
				return lhs.getY() > rhs.getY();
			});
		if (!ascend)
		{
			oss << "Sorting order: Descending" << endl;
			for (int i = 0; i < v_p2d_container.size(); i++)
			{
				oss << v_p2d_container[i] << endl;
			}
		}
		else
		{
			oss << "Sorting order: Ascending" << endl;
			for (int i = v_p2d_container.size() - 1; i >= 0; i--)
			{
				oss << v_p2d_container[i] << endl;
			}
		}
	}
	else if (length)
	{
		oss << "Sort by: Distance to Origin" << endl;
		sort(v_p2d_container.begin(), v_p2d_container.end(),
			[](Point2D lhs, Point2D rhs)
			{
				return lhs.getScalarValue() > rhs.getScalarValue();
			});
		if (!ascend)
		{
			oss << "Sorting order: Descending" << endl;
			for (int i = 0; i < v_p2d_container.size(); i++)
			{
				oss << v_p2d_container[i] << endl;
			}
		}
		else
		{
			oss << "Sorting order: Ascending" << endl;
			for (int i = v_p2d_container.size() - 1; i >= 0; i--)
			{
				oss << v_p2d_container[i] << endl;
			}
		}
	}
	return oss.str();
}

string Assn3Driver::print_Point_3D(bool X_coord, bool Y_coord, bool Z_coord, bool length, bool ascend)
{
	ostringstream oss;
	if (X_coord)
	{
		oss << "Sort by: X coordinate" << endl;
		sort(v_p3d_container.begin(), v_p3d_container.end(),
			[](Point3D lhs, Point3D rhs)
		{
				return lhs.getX() > rhs.getX();
		});

		if (!ascend)
		{
			oss << "Sorting order: Ascending" << endl;
			for (int i = 0; i < v_p3d_container.size(); i++)
			{
				oss << v_p3d_container[i] << endl;
			}
		}
		else
		{
			oss << "Sorting order: Descending" << endl;
			for (int i = v_p3d_container.size() - 1; i >= 0; i--)
			{
				oss << v_p3d_container[i] << endl;
			}
		}
	}
	if (Y_coord)
	{
		oss << "Sort by: Y coordinate" << endl;
		sort(v_p3d_container.begin(), v_p3d_container.end(),
			[](Point3D lhs, Point3D rhs)
			{
				return lhs.getY() > rhs.getY();
			});

		if (!ascend)
		{
			oss << "Sorting order: Descending" << endl;
			for (int i = 0; i < v_p3d_container.size(); i++)
			{
				oss << v_p3d_container[i] << endl;
			}
		}
		else
		{
			oss << "Sorting order: Ascending" << endl;
			for (int i = v_p3d_container.size() - 1; i >= 0; i--)
			{
				oss << v_p3d_container[i] << endl;
			}
		}
	}
	if (Z_coord)
	{
		oss << "Sort by: Z coordinate" << endl;
		sort(v_p3d_container.begin(), v_p3d_container.end(),
			[](Point3D lhs, Point3D rhs)
			{
				return lhs.getZ() > rhs.getZ();
			});

		if (!ascend)
		{
			oss << "Sorting order: Descending" << endl;
			for (int i = 0; i < v_p3d_container.size(); i++)
			{
				oss << v_p3d_container[i] << endl;
			}
		}
		else
		{
			oss << "Sorting order: Ascending" << endl;
			for (int i = v_p3d_container.size() - 1; i >= 0; i--)
			{
				oss << v_p3d_container[i] << endl;
			}
		}
	}
	if (length)
	{
		oss << "Sort by: Length" << endl;
		sort(v_p3d_container.begin(), v_p3d_container.end(),
			[](Point3D lhs, Point3D rhs)
			{
				return lhs.getScalarValue() > rhs.getScalarValue();
			});

		if (!ascend)
		{
			oss << "Sorting order: Descending" << endl;
			for (int i = 0; i < v_p3d_container.size(); i++)
			{
				oss << v_p3d_container[i] << endl;
			}
		}
		else
		{
			oss << "Sorting order: Ascending" << endl;
			for (int i = v_p3d_container.size() - 1; i >= 0; i--)
			{
				oss << v_p3d_container[i] << endl;
			}
		}
	}
	return oss.str();
}


string Assn3Driver::print_Line_Data(bool L2D, bool point_1, bool point_2, bool length, bool ascend)
{
	ostringstream oss;
	if (L2D)
	{
		oss << "Filtering by: Line2D" << endl;
		if (point_1)
		{
			oss << "Sort by: X, Y values of point 1" << endl;
			sort(v_l2d_container.begin(), v_l2d_container.end(),
				[](Line2D lhs, Line2D rhs)
				{
					bool flag = lhs.getPt1().getX() == rhs.getPt1().getX();
					if (flag)
					{
						return lhs.getPt1().getY() > rhs.getPt1().getY();
					}
					else
					{
						return lhs.getPt1().getX() > rhs.getPt1().getX();
					}
				});

			if (!ascend)
			{
				oss << "Sorting order: Descending" << endl;
				for (int i = 0; i < v_l2d_container.size(); i++)
				{
					oss << v_l2d_container[i] << endl;
				}
			}
			else
			{
				oss << "Sorting order: Ascending" << endl;
				for (int i = v_l2d_container.size() - 1; i >= 0; i--)
				{
					oss << v_l2d_container[i] << endl;
				}
			}
		}
		else if (point_2)
		{
			oss << "Sort by: X, Y values of point 2" << endl;
			sort(v_l2d_container.begin(), v_l2d_container.end(),
				[](Line2D lhs, Line2D rhs)
				{
					bool flag = lhs.getPt2().getX() == rhs.getPt2().getX();
					if (flag)
					{
						return lhs.getPt2().getY() > rhs.getPt2().getY();
					}
					else
					{
						return lhs.getPt2().getX() > rhs.getPt2().getX();
					}
				});

			if (!ascend)
			{
				oss << "Sorting order: Descending" << endl;
				for (int i = 0; i < v_l2d_container.size(); i++)
				{
					oss << v_l2d_container[i] << endl;
				}
			}
			else
			{
				oss << "Sorting order: Ascending" << endl;
				for (int i = v_l2d_container.size() - 1; i >= 0; i--)
				{
					oss << v_l2d_container[i] << endl;
				}
			}
		}
		else if (length)
		{
			oss << "Sort by: Length" << endl;
			sort(v_l2d_container.begin(), v_l2d_container.end(),
				[](Line2D lhs, Line2D rhs)
				{
					return lhs.getScalarValue() > rhs.getScalarValue();
				});

			if (!ascend)
			{
				oss << "Sorting order: Descending" << endl;
				for (int i = 0; i < v_l2d_container.size(); i++)
				{
					oss << v_l2d_container[i] << endl;
				}
			}
			else
			{
				oss << "Sorting order: Ascending" << endl;
				for (int i = v_l2d_container.size() - 1; i >= 0; i--)
				{
					oss << v_l2d_container[i] << endl;
				}
			}
		}
	}
	else
	{
		oss << "Filtering by: Line3D" << endl;
		if (length)
		{
			oss << "Sort by: Length" << endl;
			sort(v_l3d_container.begin(), v_l3d_container.end(),
				[](Line3D lhs, Line3D rhs)
				{
					return lhs.getScalarValue() > rhs.getScalarValue();
				});

			if (!ascend)
			{
				oss << "Sorting order: Descending" << endl;
				for (int i = 0; i < v_l3d_container.size(); i++)
				{
					oss << v_l3d_container[i] << endl;
				}
			}
			else
			{
				oss << "Sorting order: Ascending" << endl;
				for (int i = v_l3d_container.size() - 1; i >= 0; i--)
				{
					oss << v_l3d_container[i] << endl;
				}
			}
		}
		else if (point_1)
		{
			oss << "Sort by: X, Y values of point 1" << endl;
			sort(v_l3d_container.begin(), v_l3d_container.end(),
				[](Line3D lhs, Line3D rhs)
				{
					bool flag = lhs.getPt1().getX() == rhs.getPt1().getX();
					if (flag)
					{
						return lhs.getPt1().getY() > rhs.getPt1().getY();
					}
					else
					{
						return lhs.getPt1().getX() > rhs.getPt1().getX();
					}
				});

			if (!ascend)
			{
				oss << "Sorting order: Descending" << endl;
				for (int i = 0; i < v_l3d_container.size(); i++)
				{
					oss << v_l3d_container[i] << endl;
				}
			}
			else
			{
				oss << "Sorting order: Ascending" << endl;
				for (int i = v_l3d_container.size() - 1; i >= 0; i--)
				{
					oss << v_l3d_container[i] << endl;
				}
			}
		}
		else if (point_2)
		{
			oss << "Sort by: X, Y values of point 2" << endl;
			sort(v_l3d_container.begin(), v_l3d_container.end(),
				[](Line3D lhs, Line3D rhs)
				{
					bool flag = lhs.getPt2().getX() == rhs.getPt2().getX();
					if (flag)
					{
						return lhs.getPt2().getY() > rhs.getPt2().getY();
					}
					else
					{
						return lhs.getPt2().getX() > rhs.getPt2().getX();
					}
				});

			if (!ascend)
			{
				oss << "Sorting order: Descending" << endl;
				for (int i = 0; i < v_l3d_container.size(); i++)
				{
					oss << v_l3d_container[i] << endl;
				}
			}
			else
			{
				oss << "Sorting order: Ascending" << endl;
				for (int i = v_l3d_container.size() - 1; i >= 0; i--)
				{
					oss << v_l3d_container[i] << endl;
				}
			}
		}
	}
	return oss.str();
}


void Assn3Driver::write_txt_file()
{
	string help;
	cout << "Enter the filename you want to store records to: ";
	cin >> help;
	ofstream file(help);
	file << global_oss;
	file.close();
	switch (machinestate.i_filter_Criteria)
	{
	case 0:
		cout << p2d_unique_entries << " records were updated" << endl << endl << endl;
		break;
	case 1:
		cout << p3d_unique_entries << " records were updated" << endl << endl << endl;
		break;
	case 2:
		cout << l2d_unique_entries << " records were updated" << endl << endl << endl;
		break;
	case 3:
		cout << l3d_unique_entries << " records were updated" << endl << endl << endl;
		break;
	default:
		break;
	}
}