#pragma once
#include <Windows.h>
#include <atlstr.h>
#include <string>
#include "share_proj_resource.h"

namespace Common
{
	class ResourceCommon
	{
	private:
		ResourceCommon() = default;

		static std::wstring LoadStringFromResource(int resourceID)
		{
			CString txt;
			auto msg = txt.LoadString(resourceID);
			return std::wstring(txt);
		}

	public:

		static std::wstring GetMessageInstallSuccessfully()
		{
			return LoadStringFromResource(IDS_INSTALL_SUCCESSFULLY);
		}
	};
}
