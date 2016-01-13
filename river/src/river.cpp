#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

#include <cmath>


float xy[14][2] ={{-0.3,0},
                  {-0.3,1.55},
                  {-0.3+0.5*cos(55/180*M_PI),1.55+sin(55/180*M_PI)},
                  {-0.3,1.55+1*sin(55/180*M_PI)},
                  {-0.3+0.5*cos(55/180*M_PI),1.55+1.5*sin(55/180*M_PI)},
                  {-0.3,1.55+2*sin(55/180*M_PI)},
                  {-0.3+1.1*cos(55/180*M_PI),1.55+3.1*sin(55/180*M_PI)}, 
                  {-0.3+1.7*cos(55/180*M_PI),1.55+2.5*sin(55/180*M_PI)},
                  {-0.3+1.1*cos(55/180*M_PI),1.55+2.0*sin(55/180*M_PI)},
                  {-0.3+1.7*cos(55/180*M_PI),1.55+1.5*sin(55/180*M_PI)},
                  {-0.3+1.1*cos(55/180*M_PI),1.55+1*sin(55/180*M_PI)},
                  {-0.3+1.7*cos(55/180*M_PI),1.55+0.5*sin(55/180*M_PI)},
                  {-0.3+0.84853*cos(55/180*M_PI),1.55-0.35147*sin(55/180*M_PI)},
                  {0.3,0}};

float square[4][2]={{-0.5,0},
                    {-0.5,0.5},
                    {0.5,0.5},
                    {0.5,0},
                   };

float line[2][2]={{-0.25,0},
		  {0.25,0},
		};

int main( int argc, char** argv )
{
  ros::init(argc, argv, "points_and_lines");
  ros::NodeHandle n;
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 10);

  ros::Rate r(30);

  float f = 0.0;
  while (ros::ok())
  {

    visualization_msgs::Marker points, line_strip, line_list;
    points.header.frame_id = line_strip.header.frame_id = line_list.header.frame_id = "/laser";
    points.header.stamp = line_strip.header.stamp = line_list.header.stamp = ros::Time::now();
    points.ns = line_strip.ns = line_list.ns = "points_and_lines";
    points.action = line_strip.action = line_list.action = visualization_msgs::Marker::ADD;
    points.pose.orientation.w = line_strip.pose.orientation.w = line_list.pose.orientation.w = 1.0;



    points.id = 0;
    line_strip.id = 1;
    line_list.id = 2;



    points.type = visualization_msgs::Marker::POINTS;
    line_strip.type = visualization_msgs::Marker::LINE_STRIP;
    line_list.type = visualization_msgs::Marker::LINE_LIST;



    // POINTS markers use x and y scale for width/height respectively
    points.scale.x = 0.05;
    points.scale.y = 0.05;

    // LINE_STRIP/LINE_LIST markers use only the x component of scale, for the line width
    line_strip.scale.x = 0.05;
    line_list.scale.x = 0.1;



    // Points are green
    points.color.g = 1.0f;
    points.color.a = 1.0;

    // Line strip is blue
    line_strip.color.b = 1.0;
    line_strip.color.a = 1.0;

    // Line list is red
    line_list.color.r = 1.0;
    line_list.color.a = 1.0;



    // Create the vertices for the points and lines
    /*for (uint32_t i = 0; i < 100; ++i)
    {
      float y = 0;//= 5 * sin(f + i / 100.0f * 2 * M_PI);
      float z = 0;//= 5 * cos(f + i / 100.0f * 2 * M_PI);

      geometry_msgs::Point p;
      p.x = (int32_t)i;
      p.y = y;
      p.z = z;

      points.points.push_back(p);
      line_strip.points.push_back(p);

      // The line list needs two points for each line
      line_list.points.push_back(p);
      p.z += 1.0;
      line_list.points.push_back(p);
    }
    */
///////////////////////////////////////////////////

    //for(int i=0;i<14;i++){
    //float x = 0;
    //float y = 0;
    float z = 0;

    geometry_msgs::Point p;
    p.x = 0;//xy[i][2];
    p.y = 0.3;//xy[i][1];
    p.z = z;

    points.points.push_back(p);
    line_strip.points.push_back(p);
    //}

////////////////////////////////////////////////////
    //geometry_msgs::Point p;
    p.x = 1.55;//line[2][1];//square[i][1];
    p.y = 0.3;//line[2][2];//square[i][2];
    p.z = z;

    points.points.push_back(p);
    line_strip.points.push_back(p);
////////////////////////////////////////////////////
    p.x = 1.55+0.5*sin(45);//line[2][1];//square[i][1];
    p.y = 0.3-0.5*cos(45);//line[2][2];//square[i][2];
    p.z = z;

    points.points.push_back(p);
    line_strip.points.push_back(p);
////////////////////////////////////////////////////
    p.x = 1.55+sin(45);//line[2][1];//square[i][1];
    p.y = 0.3;//line[2][2];//square[i][2];
    p.z = z;

    points.points.push_back(p);
    line_strip.points.push_back(p);
////////////////////////////////////////////////////
    p.x = 1.55+1.5*sin(45);//line[2][1];//square[i][1];
    p.y = 0.3-0.5*cos(45);//line[2][2];//square[i][2];
    p.z = z;

    points.points.push_back(p);
    line_strip.points.push_back(p);
////////////////////////////////////////////////////
    p.x = 1.55+2*sin(45);//line[2][1];//square[i][1];
    p.y = 0.3;//line[2][2];//square[i][2];
    p.z = z;

    points.points.push_back(p);
    line_strip.points.push_back(p);
////////////////////////////////////////////////////
    p.x = 1.55+3.1*sin(45);//line[2][1];//square[i][1];
    p.y = 0.3-1.1*cos(45);//line[2][2];//square[i][2];
    p.z = z;

    points.points.push_back(p);
    line_strip.points.push_back(p);
////////////////////////////////////////////////////
    p.x = 1.55+2.5*sin(45);//line[2][1];//square[i][1];
    p.y = 0.3-1.7*cos(45);//line[2][2];//square[i][2];
    p.z = z;

    points.points.push_back(p);
    line_strip.points.push_back(p);
////////////////////////////////////////////////////
    p.x = 1.55+2.0*sin(45);//line[2][1];//square[i][1];
    p.y = 0.3-1.1*cos(45);//line[2][2];//square[i][2];
    p.z = z;

    points.points.push_back(p);
    line_strip.points.push_back(p);
////////////////////////////////////////////////////
    p.x = 1.55+1.5*sin(45);//line[2][1];//square[i][1];
    p.y = 0.3-1.7*cos(45);//line[2][2];//square[i][2];
    p.z = z;

    points.points.push_back(p);
    line_strip.points.push_back(p);
////////////////////////////////////////////////////
    p.x = 1.55+1*sin(45);//line[2][1];//square[i][1];
    p.y = 0.3-1.1*cos(45);//line[2][2];//square[i][2];
    p.z = z;

    points.points.push_back(p);
    line_strip.points.push_back(p);
////////////////////////////////////////////////////
    p.x = 1.55+0.5*sin(45);//line[2][1];//square[i][1];
    p.y = 0.3-1.7*cos(45);//line[2][2];//square[i][2];
    p.z = z;

    points.points.push_back(p);
    line_strip.points.push_back(p);
////////////////////////////////////////////////////
    p.x = 1.55-0.35147*sin(45);//line[2][1];//square[i][1];
    p.y = 0.3-0.84853*cos(45);//line[2][2];//square[i][2];
    p.z = z;

    points.points.push_back(p);
    line_strip.points.push_back(p);
////////////////////////////////////////////////////
    p.x = 0;//line[2][1];//square[i][1];
    p.y = -0.3;//line[2][2];//square[i][2];
    p.z = z;

    points.points.push_back(p);
    line_strip.points.push_back(p);
////////////////////////////////////////////////////




    marker_pub.publish(points);
    marker_pub.publish(line_strip);
    marker_pub.publish(line_list);

    r.sleep();

    f += 0.04;
  }
}
