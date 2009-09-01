//
//  PrayerDatabase.h
//  BahaiWritings
//
//  Created by Arash Payan on 8/25/08.
//  Copyright 2008 Arash Payan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <sqlite3.h>
@class PrayerView;

#import "Prayer.h"
#import "NSString_CategoryCompare.h"

extern NSString *const kBookmarksPrefKey;
extern NSString *const kRecentsPrefKey;

extern NSString *const kBookmarkKeyCategory;
extern NSString *const kBookmarkKeyTitle;

extern NSString *const kRecentsKeyCategory;
extern NSString *const kRecentsKeyTitle;
extern NSString *const kRecentsKeyAccessTime;

extern NSString *const kPrefsFontSize;

@interface PrayerDatabase : NSObject {
	sqlite3 *dbHandle;

	NSMutableArray *recentPrayers;
	NSMutableArray *bookmarkedPrayers;
	
	NSMutableArray *languages;
	NSMutableString *languageSQL;
	
	// mapping of category name (NSString*) to count (NSNumber*)
	NSMutableDictionary *categoryCountCache;
	
	BOOL prayerBeingViewed;
	PrayerView *prayerView;
}

@property(nonatomic, assign, getter=isPrayerBeingViewed) BOOL prayerBeingViewed;
@property(nonatomic, assign) PrayerView *prayerView;

+ (PrayerDatabase*)sharedInstance;
- (NSDictionary*)categories;
- (NSArray*)prayersForCategory:(NSString*)category;
- (int)numberOfPrayersForCategory:(NSString*)category;
- (void)addBookmark:(long)prayerId;
- (BOOL)prayerIsBookmarked:(long)prayerId;
- (NSArray*)getBookmarks;
- (void)clearRecents;
- (NSArray*)getRecent;
- (void)accessedPrayer:(long)prayerId;
- (void)removeBookmark:(long)prayerId;
- (Prayer*)prayerWithId:(long)prayerId;
- (NSArray*)searchWithKeywords:(NSArray*)keywords;

- (void)migrateDbFromNilTo1;
- (void)migrateDbFrom1To2;
- (void)migrateDbFrom2To3;

@end
