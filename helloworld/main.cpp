#include <osgViewer/Viewer>

#include <osg/Node>

#include <osg/Geode>

#include <osg/Group>

#include <osgDB/ReadFile>

#include <osgDB/WriteFile>

int main(int argc, char *argv[])

{
    osgViewer::Viewer viewer;
    viewer.setSceneData(osgDB::readNodeFile("/home/demo/Downloads/OpenSceneGraph-Data-3.0.0/cow.osg"));
    viewer.realize();
    viewer.run();

    return 0;
}
