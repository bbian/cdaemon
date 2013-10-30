# Copyright (c) 2012 The Chromium OS Authors. All rights reserved.
# Distributed under the terms of the GNU General Public License v2

EAPI="4"

inherit git-2

CROS_WORKON_PROJECT="chromiumos/platform/hellod"
CROS_WORKON_USE_VCSID="1"
CROS_WORKON_OUTOFTREE_BUILD=1

DESCRIPTION="Hello World Daemon POC"
HOMEPAGE=""

LICENSE="GPL-2"
SLOT="0"
KEYWORDS="amd64 arm x86"

EGIT_REPO_URI="git://github.com/bbian/cdaemon.git"

