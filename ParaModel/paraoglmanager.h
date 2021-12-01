#pragma once
#ifndef PARAOGLMANAGER_H
#define PARAOGLMANAGER_H

#include <QDockWidget>
#include <QOpenGLWidget>
#include <QKeyEvent>
#include <QTime>
#include <QOpenGLFunctions_4_3_Core>
#include <QMouseEvent>

#include"ParaType.h"
#include<resourcemanager.h>
#include "camera.h"
#include <ShaderProc.h>

struct Point//绘制所需点结构
{
	float x;
	float y;
	float z;
};
typedef vector<Point> vPoint;


class ParaOGLManager : public QOpenGLWidget
{
public:
	explicit ParaOGLManager(QWidget* parent = 0);
	~ParaOGLManager();
	
	void handleKeyPressEvent(QKeyEvent* event);
	//void keyPressEvent(QKeyEvent* event)override;			//键盘按下事件
	
	void handleKeyReleaseEvent(QKeyEvent* event);
	//void keyReleaseEvent(QKeyEvent* event)override;		//键盘释放事件


	GLboolean keys[1024];			// 获取键盘按键，实现多键触控

	enum SwitchView //相机视角枚举，七种视图（一个默认视图加六个标准视图）
	{
		NONE,
		FRONT_VIEW,
		BACK_VIEW,
		LEFT_VIEW,
		RIGHT_VIEW,
		TOP_VIEW,
		BOTTOM_VIEW
	};
	SwitchView switchView;


public:
	//绘制
	// 
	//柱
	void InitAndDrawColumn(float x,float y,float z,float radius,float height);//参数：底面圆心xz，半径，高度
	
	//多边形柱(竖着)
	void InitAndDrawPolygonColumnPortrait(VINT data,float height);

	//多边形柱(横着)
	void InitAndDrawPolygonColumnHorizontal(VINT data, float length);
																			  //长方体（墙、板等）x\y\z 为墙体最左下角的点坐标
	void InitAndDrawCuboid(float x,float y,float z,float length,float thickness,float height);

	//根据中心构件单元Id去构件库里查具体模型参数
	BasicUnit findUnit(int idx, VUNITTABLE oglUnitTable);

	VTOPOTABLE *oglTopTable;//绘制所需的拓扑结构表
	VUNITTABLE *oglUnitTable;//绘制所需的结构单元表

public:
	//相机、鼠标键入相关参数
	Camera* camera;
	GLboolean isFirstMouse;

	GLboolean isLeftMousePress;
	GLboolean isRightMousePress;
	
	GLint lastX;
	GLint lastY;
	QTime time;
	GLfloat deltaTime;
	GLfloat lastFrame;											//上一帧

	GLfloat rotateRaw;											//每次对模型的raw旋转
	GLfloat rotatePitch;										//每次对模型的pitch旋转


protected:
	void mouseMoveEvent(QMouseEvent* event);
	void wheelEvent(QWheelEvent* event) override;			//滚轮事件
	void mousePressEvent(QMouseEvent* event) override;		//鼠标按下事件
	void mouseReleaseEvent(QMouseEvent* event) override;	//鼠标释放事件
	virtual void initializeGL();
	virtual void resizeGL(int w, int h);
	virtual void paintGL();
	

	
private:
	//摄像机键盘处理函数，
	void processInput(GLfloat dt);
	//opengl 更新函数
	void updateGL();

	QOpenGLFunctions_4_3_Core* pCore;

	
	


	

	GLuint uboMatrices;
	GLuint VBO,EBO;
};



#endif // PARAOGLMANAGER_H
