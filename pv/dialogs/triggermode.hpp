/*
 * This file is part of the PulseView project.
 *
 * Copyright (C) 2012-2013 Joel Holdsworth <joel@airwebreathe.org.uk>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 */

#ifndef PULSEVIEW_PV_TRIGGERMODE_HPP
#define PULSEVIEW_PV_TRIGGERMODE_HPP

#include <memory>

#include <QDialog>
#include <QWidget>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QCheckBox>
#include <QSpinBox>
#include <QVBoxLayout>
#include <QGroupBox>

#include <pv/session.hpp>

using std::shared_ptr;

namespace pv {
namespace dialogs {

class TriggerMode : public QDialog
{
	Q_OBJECT

public:
		TriggerMode(QWidget *parent, Session &session);

private:
		Session &session_;

private Q_SLOTS:
	void chkbox_toggled(bool checked);
	void rearm_time_changed(int value);

private:
	QVBoxLayout layout_;
	QWidget form_;
	QFormLayout form_layout_;
	QDialogButtonBox button_box_;

// mode

	QCheckBox *chkbox_repetitive_;

	QVBoxLayout *vbox_mode_;
	QGroupBox *groupbox_mode_;

// delay

	QSpinBox *rearm_delay_;

	QVBoxLayout *vbox_rearm_delay_;
	QGroupBox *groupbox_rearm_delay_;
};

} // namespace dialogs
} // namespace pv

#endif // PULSEVIEW_PV_TRIGGERMODE_HPP
