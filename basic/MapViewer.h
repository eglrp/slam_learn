//
// Created by pidan1231239 on 18-7-23.
//

#ifndef SLAM_LEARN_MAPVIEWER_H
#define SLAM_LEARN_MAPVIEWER_H

#include "Map.h"
#include "common_include.h"
#include <pcl/common/common_headers.h>
#include <pcl/visualization/cloud_viewer.h>
#include <pcl/common/common_headers.h>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/point_cloud.h>
#include <pcl/visualization/pcl_visualizer.h>

namespace sky {

    class MapViewer {

    public:
        pcl::visualization::PCLVisualizer viewer;
        pcl::PointCloud<pcl::PointXYZRGB>::Ptr cloud;

        MapViewer() :
                viewer("3D Viewer"),
                cloud(new pcl::PointCloud<pcl::PointXYZRGB>) {

            viewer.setBackgroundColor(0.8, 0.8, 0.8);
            viewer.addPointCloud(cloud, "Triangulated Point Cloud");
            viewer.setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE,
                                                    3,
                                                    "Triangulated Point Cloud");
            viewer.addCoordinateSystem(1.0);
        }

        void run();

        void update(Map::Ptr map);

        ~MapViewer() {}

    private:
        KeyFrame::Ptr lastFrame;

        void threadFunc();

        void addFrame(KeyFrame::Ptr frame, string camName = "");
    };

}


#endif //SLAM_LEARN_MAPVIEWER_H
