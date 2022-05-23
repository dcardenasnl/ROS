#ifndef DEFINITIONS_H_
#define DEFINITIONS_H_

namespace amtc
{
typedef int SubscriberID;
typedef int PublisherID;
typedef int ServiceServerID;
typedef int ServiceClientID;
typedef int TimerID;
typedef int SimpleActionServerID;
typedef int SimpleActionClientID;

const static SubscriberID SubscriberID_invalid_ID = 0;
const static PublisherID PublisherID_invalid_ID = 0;
const static ServiceServerID ServiceServerID_invalid_ID = 0;
const static ServiceClientID ServiceClientID_invalid_ID = 0;
const static TimerID TimerID_invalid_ID = 0;
const static SimpleActionServerID SimpleActionServerID_invalid_ID = 0;
const static SimpleActionClientID SimpleActionClientID_invalid_ID = 0;
typedef std::string KeyWord;
typedef std::string Topic;
// typedef boost::any SimpleActionServer;
// typedef boost::any SimpleActionClient;

}  // namespace amtc

#endif