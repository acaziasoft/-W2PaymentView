//
//  PaymentCell.h
//  CustomPaymentView
//
//  Created by mac on 8/3/16.
//  Copyright © 2016 Myth. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "W2PaymentCellFormatter.h"
#import "PaymentSubview.h"

@protocol PaymentCellDelegate <NSObject>

-(void)actionForCellAtIndex:(NSInteger)index;
-(void)didEnterText:(NSString*)text forCellAtIndex:(NSInteger)index;
-(void)didEditText;
-(void)didEndEditText;
-(void)postPayment;

@end

@interface PaymentCell : UIView

@property(nonatomic)NSInteger index;
@property(nonatomic)BOOL haveInternalAction;
@property(nonatomic)id<PaymentCellDelegate> delegate;
@property(nonatomic)enum CellType cellType;
-(void)enableCellAction;
-(void)changeState;

-(PaymentSubview*)cellSubview;

@end
