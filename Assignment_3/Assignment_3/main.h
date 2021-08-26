#ifndef MAIN_H_
#define MAIN_H_
#include "Line.h"
#include "MyTemplates.h"

class Assn3Driver
{
protected:
	string s_Student_Number = "7060853";
	string s_Student_Name = "Nathan Chia Shi-Lin";
	
	struct State_of_Object
	{
		int i_filter_Criteria = 0;
		string s_filter_Criteria[4] = { "(Current: Point2D)","(Current: Point3D)","(Current: Line2D)","(Current: Line3D)" };
		
		int i_point2D_Sort = 0;
		string s_point2D_sort[3] = { "(X coordinate)","(Y Coordinate)","(Distance from Origin (0,0))" };
		
		int i_point3D_Sort = 0;
		string s_point3D_sort[4] = { "(X coordinate)","(Y Coordinate)","(Z Coordinate)","(Distance from Origin (0,0))" };
		
		int i_Line_sort = 0;
		string s_Line_sort[3] = { "(X/Y coordinates of Point 1)", "(X/Y coordinates of Point 2)","(Length of Line)" };
		
		int i_Asc_Desc_sort = 0;
		string s_Asc_Desc_sort[2] = { "(Ascending)","(Descending)" };
	};

	State_of_Object machinestate;
	vector<Point2D> v_p2d_container;
	vector<Point3D> v_p3d_container;
	vector<Line2D> v_l2d_container;
	vector<Line3D> v_l3d_container;

	string global_oss;

	int p2d_unique_entries;
	int p3d_unique_entries;
	int l2d_unique_entries;
	int l3d_unique_entries;

public:
	Assn3Driver()
	{
		p2d_unique_entries = 0;
		p3d_unique_entries = 0;
		l2d_unique_entries = 0;
		l3d_unique_entries = 0;
	}
	~Assn3Driver()
	{

	}

	void main();
	void print_Menu();
	void print_current_state();
	void print_Data();

	string print_Point_2D(bool X_coord,bool length,bool ascend);
	string print_Point_3D(bool X_coord, bool Y_coord, bool Z_coord, bool length, bool ascend);
	string print_Line_Data(bool L2D, bool point_1, bool point_2, bool length, bool ascend);

	void swap_filtering_Criteria();
	void swap_sorting_Criteria();
	void swap_asc_desc_Criteria();

	void read_txt_file();
	void write_txt_file();


	vector<string> tokenize_string(string input, string delimiter)
	{
		size_t pos = 0;
		string token;
		vector<string> result;

		while ((pos = input.find(delimiter)) != string::npos)
		{
			token = input.substr(0, pos);
			result.push_back(token);
			input.erase(0, pos + delimiter.length());
		}

		result.push_back(input);

		return result;
	}
};


#endif //MAIN_H_
