/*
 * main.cpp
 *
 *  Created on: 2014年7月12日
 *  Author: jarek
 *  Brief: 
 */

#include <cstdio>
#include <map>
#include <string>

template<typename Enum>
class EnumConvertMap
{
public:
    typedef Enum EnumType;

public:
    const char* EnumToString(EnumType e)
    {
        typename EnumToStringMap::iterator iter = enumToStringMap.find(e);
        if (iter == enumToStringMap.end())
        {
            return 0;
        }
        else
        {
            return iter->second.c_str();
        }
    }

    EnumType StringToEnum(const char* str)
    {
        typename StringToEnumMap::iterator iter = stringToEnumMap.find(
                std::string(str));
        if (iter == stringToEnumMap.end())
        {
            return EnumType(0);
        }
        else
        {
            return iter->second;
        }
    }

    void AddMap(EnumType e, const char* str)
    {
        std::string strString(str);
        enumToStringMap[e] = strString;
        stringToEnumMap[strString] = e;
    }

private:
    typedef std::map<EnumType, std::string> EnumToStringMap;
    typedef std::map<std::string, EnumType> StringToEnumMap;

    EnumToStringMap enumToStringMap;
    StringToEnumMap stringToEnumMap;
};

template<typename Enum, void (*initMap)(EnumConvertMap<Enum>& map)>
class EnumConverter
{
public:
    typedef Enum EnumType;

public:
    static const char* EnumToString(EnumType e)
    {
        Initialize();
        return enumMap.EnumToString(e);
    }

    static EnumType StringToEnum(const char* str)
    {
        Initialize();
        return enumMap.StringToEnum(str);
    }

private:
    static void Initialize()
    {
        if (initialize)
        {
            return;
        }

        initMap(enumMap);
        initialize = true;
    }

private:
    static EnumConvertMap<Enum> enumMap;
    static bool initialize;
};

template<typename Enum, void (*initMap)(EnumConvertMap<Enum>& map)>
EnumConvertMap<Enum> EnumConverter<Enum, initMap>::enumMap;

template<typename Enum, void (*initMap)(EnumConvertMap<Enum>& map)>
bool EnumConverter<Enum, initMap>::initialize;



typedef enum
{
    Male = 1,
    Female = 2,
} Player;

void EnumPairDefine(EnumConvertMap<Player>& enumMap)
{
    enumMap.AddMap(Male, "Male");
}

typedef EnumConverter<Player, EnumPairDefine> Converter;


struct Color
{
    typedef enum
    {
        Blue,
        Green,
    } Enum;

    static void EnumPairDefine(EnumConvertMap<Enum>& enumMap)
    {
        enumMap.AddMap(Blue, "Blue");
        enumMap.AddMap(Green, "Green");
    }

    typedef EnumConverter<Enum, EnumPairDefine> Converter;
};



int main()
{
    printf("%d \n", (int) Converter::StringToEnum("Male"));
    printf ("%s \n", Converter::EnumToString(Male));
    printf ("%s \n", Converter::EnumToString(Female));
    printf ("=====================================\n");

    printf("%d \n", (int) Color::Converter::StringToEnum("Green"));
    printf ("%s \n", Color::Converter::EnumToString(Color::Blue));
    printf ("%s \n", Color::Converter::EnumToString(Color::Green));

    return 0;
}
