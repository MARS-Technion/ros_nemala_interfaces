/*
Copyright 2023 David Dovrat

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#ifndef _ROS_NEMALA_INTERFACES_NEMALA_SERVICE_MESSAGE_H_
#define _ROS_NEMALA_INTERFACES_NEMALA_SERVICE_MESSAGE_H_

#include <NeMALA/MessagePropertyTree.h>
#include <boost/property_tree/xml_parser.hpp>

namespace ros_nemala_interfaces {

//--------------------------------------------------------
// 						Class NemalaTerminateMessage
//--------------------------------------------------------

/*
 * A message class to shut down dispatchers:
 */
class NemalaTerminateMessage : public NeMALA::MessagePropertyTree
{
public:

	//-------------------------- Methods ------------------------------------
	/*
	 * Init class variables.
	 * Publishers should use this function.
	 */
	NemalaTerminateMessage(int nNodeId)
	{
		m_ptNodeId.put("<xmlattr>.type", "real");
		m_ptNodeId.put("", nNodeId);
	}

	~NemalaTerminateMessage(){}

	void BuildMessage()
	{
		std::ostringstream os;
		boost::property_tree::xml_parser::write_xml(os, m_ptNodeId);

		AddElementText("Operation", "terminate");
		AddElementText("Nodes", os.str());
	}

private:
	 //-------------- Variables --------------------
	NeMALA::Proptree m_ptNodeId;
};

} //namespace ros_nemala_interfaces

#endif /* _ROS_NEMALA_INTERFACES_NEMALA_SERVICE_MESSAGE_H_ */
