/*       +------------------------------------+
 *       | Inspire Internet Relay Chat Daemon |
 *       +------------------------------------+
 *
 *  InspIRCd: (C) 2002-2009 InspIRCd Development Team
 * See: http://www.inspircd.org/wiki/index.php/Credits
 *
 * This program is free but copyrighted software; see
 *            the file COPYING for details.
 *
 * ---------------------------------------------------
 */

#include "mode.h"
#include "channels.h"

class InspIRCd;

/** Channel mode +b
 */
class ModeChannelBan : public ModeHandler
{
 private:
	BanItem b;
 public:
	ModeChannelBan(InspIRCd* Instance);
	ModeAction OnModeChange(User* source, User* dest, Channel* channel, std::string &parameter, bool adding, bool servermode);
	std::string& AddBan(User *user,std::string& dest,Channel *chan,int status, bool servermode);
	std::string& DelBan(User *user,std::string& dest,Channel *chan,int status);
	void DisplayList(User* user, Channel* channel);
	void DisplayEmptyList(User* user, Channel* channel);
	ModePair ModeSet(User* source, User* dest, Channel* channel, const std::string &parameter);
	void RemoveMode(User* user, irc::modestacker* stack = NULL);
	void RemoveMode(Channel* channel, irc::modestacker* stack = NULL);
};

