/*
    This file is part of Helio Workstation.

    Helio is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    Helio is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Helio. If not, see <http://www.gnu.org/licenses/>.
*/

#include "Common.h"
#include "XmlSerializer.h"

Result XmlSerializer::saveToFile(File file, const ValueTree &tree) const
{
    const auto saved = file.replaceWithText(tree.toXmlString());
    return saved ? Result::ok() : Result::fail({});
}

Result XmlSerializer::loadFromFile(const File &file, ValueTree &tree) const
{
    XmlDocument document(file);
    ScopedPointer<XmlElement> xml(document.getDocumentElement());
    if (xml != nullptr)
    {
        tree = ValueTree::fromXml(*xml);
        return Result::ok();
    }

    return Result::fail("Failed to parse xml data");
}

Result XmlSerializer::saveToString(String &string, const ValueTree &tree) const
{
    string = tree.toXmlString();
    return Result::ok();
}

Result XmlSerializer::loadFromString(const String &string, ValueTree &tree) const
{
    XmlDocument document(string);
    ScopedPointer<XmlElement> xml(document.getDocumentElement());
    tree = ValueTree::fromXml(*xml);
    return Result::ok();
}

bool XmlSerializer::supportsFileWithExtension(const String &extension) const
{
    return extension.endsWithIgnoreCase("xml");
}

bool XmlSerializer::supportsFileWithHeader(const String &header) const
{
    return header.startsWithIgnoreCase("<?xml");
}
