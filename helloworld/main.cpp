#include <osgViewer/Viewer>

#include <osgViewer/ViewerEventHandlers>

#include <osgGA/StateSetManipulator>
#include <osgGA/TrackballManipulator>
#include <osgGA/FlightManipulator>
#include <osgGA/DriveManipulator>
#include <osgGA/KeySwitchMatrixManipulator>
#include <osgGA/AnimationPathManipulator>
#include <osgGA/TerrainManipulator>

#include <osg/Node>

#include <osg/Geode>

#include <osg/Geometry>

#include <osg/Group>

#include <osg/MatrixTransform>

#include <osgDB/ReadFile>

#include <osgDB/WriteFile>

using namespace osg;
using namespace osgViewer;
using namespace osgDB;

ref_ptr<Node> createQuad();

int main(int argc, char *argv[])

{
    Viewer viewer;
    ref_ptr<Group> root = new Group();
    ref_ptr<Node> cow1 = readNodeFile("/home/demo/Downloads/OpenSceneGraph-Data-3.0.0/cow.osg");
    ref_ptr<Node> robot1 = readNodeFile("/home/demo/Downloads/OpenSceneGraph-Data-3.0.0/robot.osg");
    ref_ptr<MatrixTransform> trans = new MatrixTransform;
    trans->setMatrix(Matrix::translate(0,0,8));
    trans->addChild(cow1.get());
    trans->addChild(robot1.get());

    ref_ptr<MatrixTransform> scale = new MatrixTransform;
    scale->setMatrix(Matrix::scale(0.5,0.5,0.5)*Matrix::translate(0,0,-8));
    scale->addChild(cow1.get());

    ref_ptr<MatrixTransform> rot = new MatrixTransform;
    rot->setMatrix(Matrix::rotate(DegreesToRadians(45.0), 1, 0, 0)*Matrix::scale(0.4,0.4,0.4)*Matrix::translate(16, 0, -8));
    rot->addChild(cow1.get());

//    Group * root = new Group();
//    Node *cow = readNodeFile("/home/demo/Downloads/OpenSceneGraph-Data-3.0.0/cow.osg");
//    cow->asGroup()->addChild(readNodeFile("/home/demo/Downloads/OpenSceneGraph-Data-3.0.0/robot.osg"));
//    root->addChild(cow);
//    root->addChild(readNodeFile("/home/demo/Downloads/OpenSceneGraph-Data-3.0.0/glider.osg"));
//    root->addChild(readNodeFile("/home/demo/Downloads/OpenSceneGraph-Data-3.0.0/robot.osg"));
//    viewer.setSceneData(readNodeFile("/home/demo/Downloads/OpenSceneGraph-Data-3.0.0/osgcool.osg"));

    viewer.addEventHandler(new osgGA::StateSetManipulator(viewer.getCamera()->getOrCreateStateSet()));
    viewer.addEventHandler(new WindowSizeHandler);
    viewer.addEventHandler(new StatsHandler);
    {
        ref_ptr<osgGA::KeySwitchMatrixManipulator> keyswitchManipulator = new osgGA::KeySwitchMatrixManipulator;
        keyswitchManipulator->addMatrixManipulator('1', "Trackball", new osgGA::TrackballManipulator());
        keyswitchManipulator->addMatrixManipulator('2', "Flight", new osgGA::FlightManipulator());
        keyswitchManipulator->addMatrixManipulator('3', "Drive", new osgGA::DriveManipulator());
        keyswitchManipulator->addMatrixManipulator('4', "Terrain", new osgGA::TerrainManipulator());
        viewer.setCameraManipulator(keyswitchManipulator.get());

    }

    viewer.addEventHandler(new RecordCameraPathHandler);

    root->addChild(cow1.get());
    root->addChild(trans.get());
    root->addChild(scale.get());
    root->addChild(rot.get());
    viewer.setSceneData(root.get());

    viewer.realize();
    viewer.run();

    return 0;
}
