//
//  AddressObject.h
//  SRPLS
//
//  Created by mac on 7/27/16.
//  Copyright © 2016 Tarar. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AddressObject : NSObject

@property(nonatomic, strong)NSString *fullName;
@property(nonatomic, strong)NSString *streetAddress;
@property(nonatomic, strong)NSString *city;
@property(nonatomic, strong)NSString *state;
@property(nonatomic, strong)NSString *zip;
@property(nonatomic, strong)NSString *phone;
+(AddressObject*)addressWithDict:(NSDictionary*)dict;

@end
