#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "ros_msg_parser/ros_parser.hpp"
#include "rosbag/bag.h"
#include "rosbag/view.h"
#include "rosbag/message_instance.h"
#include <iomanip>
#include <chrono>
#include <nlohmann/json.hpp>

int main() {
  std::string dir_path{ R"(D:\documents\bag\carly_bag\diag-2024-10-10_13-48-34)" };

  std::set<std::string> bag_paths;
  for (const auto& sub_path : std::filesystem::directory_iterator(dir_path)) {
    if (std::filesystem::path(sub_path).extension().string() == ".bag") {
      bag_paths.insert(sub_path.path().string());
      continue;
    }
  }

  std::string output_bag = "merged.bag";

  // 创建输出 bag
  rosbag::Bag outbag;
  try {
    outbag.open(output_bag, rosbag::bagmode::Write);
  }
  catch (std::exception& e) {
    std::cerr << "❌ 无法创建输出 bag: " << e.what() << std::endl;
    return -1;
  }

  // 遍历所有输入 bag
  for (const std::string& bag_file : bag_paths) {

    std::cout << "📂 处理 bag 文件: " << bag_file << std::endl;

    try {
      rosbag::Bag bag;
      bag.open(bag_file, rosbag::bagmode::Read);

      rosbag::View view(bag);
      for (const rosbag::MessageInstance& msg : view) {
        outbag.write(msg.getTopic(), msg.getTime(), msg);
      }

      bag.close();
    }
    catch (rosbag::BagException& e) {
      std::cerr << "❌ 读取 bag 失败: " << bag_file << " -> " << e.what() << std::endl;
    }
  }

  // 关闭输出 bag
  outbag.close();
  std::cout << "✅ 合并完成: " << output_bag << std::endl;
}