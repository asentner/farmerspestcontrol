Introduction
____________

Easily embed Drupal blocks in nodes, other blocks, or anywhere text formats 
are allowed using the Shortcode (https://codex.wordpress.org/Shortcode) 
syntax common in Wordpress.

WHY?
____

We've often come across situtations where we need to place a block on a page 
somewhere that Drupal's regions wouldn't allow (e.g., within paragraphs of 
text in a Node). The shortcode syntax provides a straightforward, secure 
way to do this.


REQUIREMENTS
------------
This module requires the following modules:
 * Block (https://drupal.org/project/block)

INSTALLATION
------------
 * Install as you would normally install a contributed drupal module. See:
  https://drupal.org/documentation/install/modules-themes/modules-7
  for further information.

CONFIGURATION
-------------

  * Add the Block Shortcode filter to any desired text format 
  (Configure > Text Formats).
  * Now anytime you want to embed a block, copy the shortcode example from 
  the Block's configuration page and paste into the place you want the block 
  to appear.

MAINTAINERS
-----------

SeanFitzpatrick, https://drupal.org/user/557214
