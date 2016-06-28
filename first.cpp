#include <osgViewer/Viewer>  
  
#include <osgDB/ReadFile>  
  
#include <osg/DrawPixels>  
  
#include <osg/Geode>  
  
#include <osg/MatrixTransform>  
  
#include <osgViewer/ViewerEventHandlers>  
  
#include <osgGA/StateSetManipulator>  
  
  
int main()  
  
{  
  
osgViewer::Viewer viewer;  
  
  
//添加状态事件  
  
viewer.addEventHandler( new osgGA::StateSetManipulator(viewer.getCamera()->getOrCreateStateSet()) );  
  
//窗口大小变化事件  
  
viewer.addEventHandler(new osgViewer::WindowSizeHandler);  
  
//添加一些常用状态设置  
  
viewer.addEventHandler(new osgViewer::StatsHandler);  
  
  
osg::Group *root = new osg::Group();  
  
osg::ref_ptr < osg::Node> b25 = osgDB::readNodeFile("F://Models//B25//B25.IVE") ;  
  
  
// 对模型进行变换  
  
osg::ref_ptr < osg::MatrixTransform> scale = new osg::MatrixTransform ;  
  
scale ->setMatrix(osg::Matrix::rotate(osg::DegreesToRadians(45.0), 1, 0, 0)*osg::Matrix::scale(0.5, 0.5, 0.5)*osg::Matrix::translate(4, 0, -2)) ;  
  
scale ->addChild(b25.get()) ;  
  
  
root->addChild(scale.get());  
  
viewer.setSceneData(root);  
  
  
viewer.realize();   
  
return viewer.run();  
  
  
//return 0;  
  
} 