/* 
 * Adium is the legal property of its developers, whose names are listed in the copyright file included
 * with this source distribution.
 * 
 * This program is free software; you can redistribute it and/or modify it under the terms of the GNU
 * General Public License as published by the Free Software Foundation; either version 2 of the License,
 * or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even
 * the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General
 * Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License along with this program; if not,
 * write to the Free Software Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#import <Adium/AIWindowController.h>

@class ESFileTransfer, ESFileTransferProgressRow, AIVariableHeightOutlineView;

@interface ESFileTransferProgressWindowController : AIWindowController <NSOutlineViewDelegate, NSOutlineViewDataSource> {
	NSMutableArray				*progressRows;
	
	IBOutlet NSScrollView					*scrollView;
	IBOutlet AIVariableHeightOutlineView	*outlineView;
	
	IBOutlet NSButton						*button_clear;
	IBOutlet NSTextField					*textField_statusBar;

	BOOL						shouldScrollToNewFileTransfer;
}

+ (id)showFileTransferProgressWindow;

+ (id)showFileTransferProgressWindowIfNotOpen;
+ (void)removeFileTransfer:(ESFileTransfer *)inFileTransfer;

- (IBAction)clearAllCompleteTransfers:(id)sender;

//For use by ESFileTransferProgressRow
- (void)progressRowDidAwakeFromNib:(ESFileTransferProgressRow *)progressView;
- (void)fileTransferProgressRow:(ESFileTransferProgressRow *)inRow
			  heightChangedFrom:(CGFloat)oldHeight
							 to:(CGFloat)newHeight;
- (void)progressRowDidChangeType:(ESFileTransferProgressRow *)progressRow;
- (void)progressRowDidChangeStatus:(ESFileTransferProgressRow *)progressRow;

- (void)_removeFileTransferRow:(ESFileTransferProgressRow *)progressRow;

@end