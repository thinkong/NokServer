#pragma warning(disable : 4819)

#include <cstdlib>
#include <iostream>
#include <boost/aligned_storage.hpp>
#include <boost/array.hpp>
#include <boost/bind.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/asio.hpp>

#include "Server.h"
#include "User.h"

#include "WaitFreeQueue.h"