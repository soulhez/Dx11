#pragma once

#ifndef LightDemo_H
#define LightDemo_H

#include "resource.h"
#include <d3dcompiler.h>
#include <directxmath.h>
#include "d3dApp.h"
#include "LightHelper.h"

using namespace DirectX;


class LightDemo : public D3DApp
{
public:
	// 顶点Shader的传入参数
	struct Vertex
	{
		XMFLOAT3 Pos;
		XMFLOAT3 Normal;
	};

	// 常量缓存
	struct FrameConstantBuffer
	{
		DirectionalLight gDirLight;
		PointLight gPointLight;
		SpotLight gSpotLight;
		XMFLOAT3 gEyePosW;
	};

	struct ConstantBuffer
	{
		XMMATRIX gWorld;
		XMMATRIX gWorldInvTranspose;
		XMMATRIX gWorldViewProj;
		Material gMaterial;
	};

public:
	LightDemo(HINSTANCE hInstance);
	~LightDemo();

	bool Init();
	void OnResize();
	void UpdateScene(float dt);
	void DrawScene();

	void OnMouseDown(WPARAM btnState, int x, int y);
	void OnMouseUp(WPARAM btnState, int x, int y);
	void OnMouseMove(WPARAM btnState, int x, int y);

private:
	void BuildGeometryBuffers();
	void BuildFX();

	float GetHeight(float x, float z) const;
	XMFLOAT3 GetNormal(float x, float z) const;

private:
	ID3D11InputLayout* mVertexLayout;	// 顶点布局
	ID3D11VertexShader* mVertexShader;	// 顶点Shader
	ID3D11PixelShader* mPixelShader;	// 片元Shader

	ID3D11Buffer* mBoxVB;	// 顶点缓冲
	ID3D11Buffer* mBoxIB;	// 索引缓冲

	// 常量缓冲
	ID3D11Buffer* mBoxCB;	
	ID3D11Buffer* mFrameBoxCB;

	// 常量数据结构
	ConstantBuffer mCBuffer;	
	FrameConstantBuffer mFrameCBuffer;

	DirectX::XMFLOAT4X4 mWorld;
	DirectX::XMFLOAT4X4 mView;
	DirectX::XMFLOAT4X4 mProj;
	XMFLOAT3 mEyePosW;

	float mTheta;
	float mPhi;
	float mRadius;

	POINT mLastMousePos;

	UINT mGridIndexCount;

	DirectionalLight mDirLight;
	PointLight mPointLight;
	SpotLight mSpotLight;
	Material mWavesMat;

};

#endif