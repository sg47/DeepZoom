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

#include "SceneObjectMesh.h"

class SceneObjectImage : public ImplementSmartObject
    <
        SceneObjectImage, 
        ClassFlags<CF_ALIGNED_MEMORY>,
        InheritImplementation<SceneObject>, 
        ISceneObjectImage,
        ICalibrable
    >
{
    WCHAR* m_pFilePath;
    SmartPtr<IImageLoader> m_spImageLoader;
    HRESULT SetFilePath(__in_z const WCHAR *filePath);

    BOOL m_IsCalibrated;

public:
    SceneObjectImage(void);
    ~SceneObjectImage(void);

	HRESULT Initialize(__in_z const WCHAR *nodeName, __in_z const WCHAR *filePath);
    HRESULT GetImageLoader(__deref_out IImageLoader **ppImageLoader);
    HRESULT Destroy();
    HRESULT Calibrate();
    BOOL IsCalibrated();
    void SetCalibrated();
};

