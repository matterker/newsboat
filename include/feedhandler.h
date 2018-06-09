#ifndef NEWSBOAT_FEEDHANDLER_H_
#define NEWSBOAT_FEEDHANDLER_H_

#include <memory>
#include <string>
#include <vector>

#include "rss.h"

namespace newsboat {
class FeedHandler {
public:
	FeedHandler();

	void sort_feeds(const std::vector<std::string>& sortmethod_info);
	std::shared_ptr<rss_feed> get_feed(const unsigned int pos);
	void add_feed(const std::shared_ptr<rss_feed> feed);
	void mark_all_feed_items_read(const unsigned int feed_pos);
	unsigned int get_feed_count_per_tag(const std::string& tag);
	std::shared_ptr<rss_feed> get_feed_by_url(const std::string& feedurl);
	void populate_query_feeds();
	unsigned int get_pos_of_next_unread(unsigned int pos);
	unsigned int feeds_size();
	void reset_feeds_status();
	void set_feeds(const std::vector<std::shared_ptr<rss_feed>> new_feeds);
	std::vector<std::shared_ptr<rss_feed>> get_all_feeds();
	void clear_feeds_items();

	std::vector<std::shared_ptr<rss_feed>> feeds;

private:
	std::mutex feeds_mutex;
};
} // namespace newsboat

#endif /* NEWSBOAT_FEEDHANDLER_H_ */
