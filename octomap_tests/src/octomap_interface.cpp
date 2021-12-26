#include <octomap_tests/octomap_interface.hpp>

OctomapInterface::OctomapInterface():
  Node("ros_node_name"),
  octree_map_data_(0.05)
{
}

void OctomapInterface::createFakeCloud() 
{
  using point3d = octomap::point3d;

  point3d origin (0.01f, 0.01f, 0.02f);
  point3d point_on_surface (2.01f, 0.01f, 0.01f);

  std::cout << "Generating sphere at " << origin << " ..." << std::endl;

  unsigned sphere_beams = 500;
  double angle = 2.0*M_PI/double(sphere_beams);
  for (unsigned i=0; i<sphere_beams; i++) {
    for (unsigned j=0; j<sphere_beams; j++) {
      octomap_cloud_.push_back(origin+point_on_surface);
      point_on_surface.rotate_IP (0,0,angle);
    }
    point_on_surface.rotate_IP (0,angle,0);
  }
  octree_map_data_.insertPointCloud(octomap_cloud_, origin);
}

void OctomapInterface::castingRaysInSphere() 
{
  using point3d = octomap::point3d;

  point3d direction = point3d (1.0,0.0,0.0);
  point3d obstacle(0,0,0);

  unsigned int hit (0);
  unsigned int miss (0);
  unsigned int unknown (0);
  double mean_dist(0);

  octomap::OcTree sampled_surface (0.05);  

  point3d origin (0.01f, 0.01f, 0.02f);
  unsigned sphere_beams = 500;
  double angle = 2.0*M_PI/double(sphere_beams);
  for (unsigned i=0; i<sphere_beams; i++)
  {
    for (unsigned j=0; j<sphere_beams; j++) {
      if (!octree_map_data_.castRay(origin, direction, obstacle, false, 3.))
      {
        // hit unknown
        if (!octree_map_data_.search(obstacle))
        {
          unknown++;
        }
        else
        {
          miss++;
        }
      }
      else
      {
        hit++;
        mean_dist += (obstacle - origin).norm();
        sampled_surface.updateNode(obstacle, true);
      }
      direction.rotate_IP (0,0,angle);
    }
    direction.rotate_IP (0,angle,0);
  }
}