//
// Copyright (C) 2013, Alojz Kovacik, http://kovacik.github.com
//
// This file is part of Deep Zoom.
//
// Deep Zoom is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Deep Zoom is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Deep Zoom. If not, see <http://www.gnu.org/licenses/>.
//


#pragma once

class TextureShader
	: public ImplementSmartObject
	<
		TextureShader, 
        InheritImplementation<BaseShader>, 	
		ITextureShader
	>
{
private:

	struct MatrixBufferType
	{
		DirectX::XMMATRIX mWorld;
		DirectX::XMMATRIX mView;
		DirectX::XMMATRIX mProjection;
	};

	struct PixelBufferType
	{
		DirectX::XMFLOAT4 pixelColor;
	};

	SmartPtr<ID3D11Buffer> m_spMatrixBuffer;
	SmartPtr<ID3D11SamplerState> m_spSampleState;

	static const D3D11_INPUT_ELEMENT_DESC m_InputLayout[];


protected:
	HRESULT InitializeConstantBuffers(__in ID3D11Device* pDevice);

public:
	TextureShader();
	~TextureShader();

	HRESULT Initialize(__in ID3D11Device* pDevice, __in ID3D11DeviceContext* pDeviceContext);
	HRESULT SetShaderParametersAndTexture(__in DirectX::CXMMATRIX worldMatrix, __in DirectX::CXMMATRIX viewMatrix, __in DirectX::CXMMATRIX projectionMatrix, __in ID3D11ShaderResourceView* texture);
};