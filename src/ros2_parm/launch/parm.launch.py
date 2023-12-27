from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package="parm_node",
            executable="node_01",
            name="custom_parameter_node",
            output="screen",
            emulate_tty=True,
            parameters=[
                {"name": "John"}
            ]
        )
    ])

