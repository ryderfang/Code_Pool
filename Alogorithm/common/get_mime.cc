#include <iostream>
#include <string>
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")

std::wstring get_mine_type(const std::wstring& file_name) {
    LPWSTR pwzMimeOut = NULL;
    FILE* fp = NULL;

    _wfopen_s(&fp, file_name.c_str(), L"r");
    scoped_ptr<char> buf(new char[256]);
    int read_sz = fread(buf.get(), sizeof(char), 256, fp);
    HRESULT hr = ::FindMimeFromData(NULL, file_name.c_str(), buf.get(), read_sz,
        NULL, FMFD_URLASFILENAME, &pwzMimeOut, 0x0);
    fclose(fp);

    if (SUCCEEDED(hr)) {
        std::wstring strResult(pwzMimeOut);
        ::CoTaskMemFree(pwzMimeOut);
        return strResult;
    }
    return std::wstring(L"application/octet-stream");
}

int main() {
    std::wstring name;
    std::wcin.imbue(locale(""));
    std::wcout.imbue(locale(""));
    while (getline(std::wcin, name)) {
        std::wcout << name << " " << get_mine_type(name) << std::endl;
    }

    return 0;
}
