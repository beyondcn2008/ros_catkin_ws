# ros_catkin_ws


手工下载terminal_color.py文件到/user/lib/python2.7/dist-packages/catkin_pkg下面：
https://raw.githubusercontent.com/catkin/catkin_tools/master/catkin_tools/terminal_color.py

./src/catkin/bin/catkin_make_isolated -DCMAKE_BUILD_TYPE=Release --install -DCATKIN_ENABLE_TESTING=0

若编译过程中出现某个已经编译过的包（它其实是在devel_isolated目录下面的）找不到，则在命令行添加-DCMAKE_PREFIX_PATH，例如：
 ./src/catkin/bin/catkin_make_isolated -DCMAKE_BUILD_TYPE=Release --pkg control_toolbox -DCMAKE_PREFIX_PATH=/home/cmm/ros_catkin_ws/devel_isolated/realtime_tools
 -DCMAKE_PREFIX_PATH=/home/cmm/ros_catkin_ws/devel_isolated/realtime_tools这个指定了realtime_tools包的安装位置


dependence:
sudo apt install cmake python-empy libconsole-bridge-dev libpoco-dev libboost-all-dev libeigen3-dev  qt5-default  libjpeg-dev libtiff5-dev   python-sip-dev  gazebo9  libtinyxml2-dev libtinyxml-dev python-pyqt5 libcurl4-gnutls-dev libresource-retriever-dev liblz4-dev   libfltk1.3-dev google-mock liburdfdom-dev libassimp-dev  liboctomap-dev libqhull-dev uuid-dev pyqt5-dev  liblz4-dev   libfltk1.3-dev google-mock liburdfdom-dev libassimp-dev  liboctomap-dev libqhull-dev uuid-dev libbz2-dev libgazebo9-dev libpolled-camera-dev libfcl-dev  libpcl-dev libgtk2.0-dev libglew-dev 

