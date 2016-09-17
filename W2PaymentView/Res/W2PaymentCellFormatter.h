//
//  CellFormatObject.h
//  w2custom
//
//  Created by mac on 8/15/16.
//  Copyright © 2016 Myth. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface W2PaymentCellFormatter : NSObject

enum CellType {
    W2PaymentCellAddress=0,
    W2PaymentCellEnterText,
    W2PaymentCellOutletAction,
    W2PaymentCellDefault,
    W2PaymentCellSwipe,
    W2PaymentCellPayment,
    W2PaymentCellHaveSubview
};

@property(nonatomic) enum CellType cellType;
@property(nonatomic, strong)NSString *cellTitle;
@property(nonatomic, strong)NSString *cellPlaceHolder;
@property(nonatomic, strong)UIImage *imageStateOpen;
@property(nonatomic, strong)UIImage *imageStateClose;

@end
