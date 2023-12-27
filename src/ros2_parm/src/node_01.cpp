
#include <rclcpp/rclcpp.hpp>
#include <chrono>
#include <string>
#include <functional>

using namespace std::chrono_literals;

class ParametersNode : public rclcpp::Node
{
public:
    ParametersNode()
        : Node("parameter_node")
    {
        //定义名字为name的参数默认值为Unknown
        this->declare_parameter<std::string>("name", "Unknown");
        //获取参数名字为name的值
        this->get_parameter("name", parameter_string_);
        RCLCPP_INFO(this->get_logger(), "name: %s", parameter_string_.c_str());
    }

private:
    std::string parameter_string_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<ParametersNode>());
    rclcpp::shutdown();
    return 0;
}

