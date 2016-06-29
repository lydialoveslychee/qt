#include <QCoreApplication>

#include <osgDB/ReadFile>

#include <osgViewer/Viewer>

#include <osg/Node>

#include <osg/Geode>

#include <osg/Geometry>

using namespace osg;
using namespace osgDB;
using namespace osgViewer;

ref_ptr<Node> createQuad();

int main(int argc, char *argv[])
{
    Viewer viewer;
    Group *root = new Group();
    root->addChild(createQuad().get());
    viewer.setSceneData(root);
    viewer.realize();
    viewer.run();
    return 0;
}

ref_ptr<Node> createQuad() {
    ref_ptr<Geometry> geom = new Geometry;
    //define four points
    ref_ptr<Vec3Array> v = new Vec3Array;
    geom->setVertexArray(v.get());
    v->push_back(Vec3(-1.f,0.f,-1.f));//Similar to vector
    v->push_back(Vec3(1.f,0.f,-1.f));
    v->push_back(Vec3(1.f,0.f,1.f));
    v->push_back(Vec3(-1.f,0.f,1.f));

    //define the color array
    ref_ptr<Vec4Array> c = new Vec4Array;
    geom->setColorArray(c.get());
    geom->setColorBinding(Geometry::BIND_PER_VERTEX);
    c->push_back(Vec4(1.f,0.f,0.f,1.f));//Vec4(R, G, B, A)
    c->push_back(Vec4(0.f,1.f,0.f,1.f));
    c->push_back(Vec4(0.f,0.f,1.f,1.f));
    c->push_back(Vec4(1.f,1.f,1.f,1.f));

    //define the normal array
    ref_ptr<Vec3Array> n = new Vec3Array;
    geom->setNormalArray(n.get());
    geom->setNormalBinding(Geometry::BIND_OVERALL);
    n->push_back(Vec3(0.f,-1.f,0.f));

    //set the Primitive
    geom->addPrimitiveSet(new DrawArrays(PrimitiveSet::QUADS,0,4));

    //Nodes for Geometry group
    ref_ptr<Geode> geode = new Geode;
    geode->addDrawable(geom.get());
    return geode.get();
}
