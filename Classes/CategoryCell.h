//
//  CategoryCell.h
//  BahaiWritings
//
//  Created by Arash Payan on 8/31/08.
//  Copyright 2008 Arash Payan. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "RoundedRectangleView.h"


@interface CategoryCell : UITableViewCell {
	UILabel *categoryLabel;
	UILabel *countLabel;
	RoundedRectangleView *roundedRectangle;
}

- (void)setCategory:(NSString*)aCategory;
- (void)setCount:(NSString*)aCount;

@end
